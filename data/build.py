#!/usr/bin/python
##-------------------------------##
## Pokemon Data Builder          ##
## Written By: Ryan Smith        ##
##-------------------------------##

## Imports
from configparser import ConfigParser
from pathlib import Path
from typing import Any, TextIO

## Constants
TYPE_CHART_INPUT: Path = Path("./types.ini")
TYPE_CHART_OUTPUT: Path = Path("./element.hpp")


## Functions
def write_type_header(file_input: Path, file_output: Path) -> None:
    """Read types.ini file and produce a C++ header file"""
    type_chart: ConfigParser = ConfigParser(inline_comment_prefixes=';')
    type_chart.read(file_input)
    fp: TextIO = file_output.open('w')
    type_count: int = len(type_chart.sections())
    type_enums: list[str] = []
    type_names: list[str] = []
    type_lookups: dict[str, dict[str, list[str]]] = {}
    type_length: int = 0
    # -Iterate over types to get largest string
    for section in type_chart.sections():
        _len: int = len(section) + 1
        if _len > type_length:
            type_length = _len
    # -Iterate over type matches
    for i, attack_type in enumerate(type_chart.sections()):
        spacer: str = ' ' * (type_length - len(attack_type))
        type_enums.append(attack_type + spacer + f"= {i:3}")
        type_names.append(f"[ELEMENT_NAME({attack_type})]" + spacer + f"= \"{attack_type}\"")
        type_lookups[attack_type] = {}
        for defense_type_1, value_1 in type_chart[attack_type].items():
            defense_type_1 = defense_type_1.capitalize()
            type_lookups[attack_type][defense_type_1] = []
            for defense_type_2, value_2 in type_chart[attack_type].items():
                multiplier = float(value_1)
                defense_type_2 = defense_type_2.capitalize()
                if defense_type_1 != defense_type_2:
                    multiplier *= float(value_2)
                # -[Attack][Defense 1][Defense 2]
                type_lookups[attack_type][defense_type_1].append(f"[ELEMENT_NAME({defense_type_2})] = {multiplier}f")
                
    # -Write to file
    # --Header
    fp.writelines([
        "#pragma once\n",
        "#include <stdint.h>\n",
        "#include <array>\n",
        "#include <string>\n",
        '\n',
        f"#define ELEMENT_COUNT {type_count}\n",
        f"#define ELEMENT_NAME(name) static_cast<std::underlying_type<ElementType>::type>(ElementType::name)\n",
        f"#define ELEMENT_VALUE(value) static_cast<std::underlying_type<ElementType>::type>(value)\n",
        '\n',
    ])
    # --Enum
    fp.writelines([
        "enum class ElementType : uint8_t\n",
        "{\n",
        *(f"\t{enum_value},\n" for enum_value in type_enums),
        "};\n",
        '\n',
    ])
    # --Name
    fp.writelines([
        "const std::array<const std::string, ELEMENT_COUNT> ElementNameLookupTable = {{\n",
        *(f"\t{name_value},\n" for name_value in type_names),
        "}};\n",
        '\n',
    ])
    # --Multiplier
    fp.writelines([
        f"// [Attack Type][Defense Type 1][Defense Type 2]\n",
        "const std::array<std::array<std::array<float, ELEMENT_COUNT>, ELEMENT_COUNT>, ELEMENT_COUNT> ElementMultiplierLookupTable = {{\n",
    ])
    for attack_type, defense_types in type_lookups.items():
        fp.write(f"\t[ELEMENT_NAME({attack_type})] = {{{{\n")
        for defense_type_1, defense_types_2 in defense_types.items():
            fp.write(f"\t\t[ELEMENT_NAME({defense_type_1})] = {{{{\n")
            for defense_type_2 in defense_types_2:
                fp.write(f"\t\t\t{defense_type_2},\n")
            fp.write("\t\t}},\n")
        fp.write("\t}},\n")
    fp.write("}};\n")
    fp.close()


## Body
write_type_header(TYPE_CHART_INPUT, TYPE_CHART_OUTPUT)
