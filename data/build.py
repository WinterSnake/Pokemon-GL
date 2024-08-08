#!/usr/bin/python
##-------------------------------##
## Pokemon Data Builder          ##
## Written By: Ryan Smith        ##
##-------------------------------##

## Imports
import json
from configparser import ConfigParser
from pathlib import Path
from typing import Any, TextIO

## Constants
POKEMON_MOVE_INPUT: Path = Path("./moves")
POKEMON_MOVE_OUTPUT: Path = Path("./moves.hpp")
POKEMON_SPECIES_INPUT: Path = Path("./pokemon/")
POKEMON_SPECIES_OUTPUT: Path = Path("./species.hpp")
TYPE_CHART_INPUT: Path = Path("./types.ini")
TYPE_CHART_OUTPUT: Path = Path("./element.hpp")


## Functions
def write_element_header(file_input: Path, file_output: Path) -> None:
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
        f"#define ELEMENT_NAME(name) static_cast<std::underlying_type<ElementType>::type>(ElementType::name)\n",
        f"#define ELEMENT_VALUE(value) static_cast<std::underlying_type<ElementType>::type>(value)\n",
        '\n',
        "constexpr size_t ELEMENT_COUNT = 18;\n",
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
        "constexpr std::array<std::array<std::array<const float, ELEMENT_COUNT>, ELEMENT_COUNT>, ELEMENT_COUNT> ElementMultiplierLookupTable = {{\n",
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


def write_moves_header(input_path: Path, output_file: Path) -> None:
    """"""
    moves = []
    move_name_len: int = 0
    for move_file in input_path.glob("*.json"):
        with move_file.open('r') as f:
            moves.append(json.load(f))
    with output_file.open('w') as f:
        f.writelines([
            "#pragma once\n",
            "#include <array>\n",
            "#include <string>\n",
            "#include \"pokemon.hpp\"\n",
            '\n',
            f"constexpr size_t MOVES_COUNT = {len(moves)};\n",
            "const std::array<const MoveInfo, MOVES_COUNT> POKEMON_MOVES = {{\n"
        ])
        for move in moves:
            if len(move['name']) > move_name_len:
                move_name_len = len(move['name'])
            f.writelines([
                "\t{\n",
                f"\t\t.Name = \"{move['name']}\",\n",
                f"\t\t.Type = ElementType::{move['type']},\n",
                f"\t\t.Category = MoveInfo::Category::{move['category']},\n",
                f"\t\t.PP = {move['pp'][0]}, .MaxPP = {move['pp'][1]},\n",
                f"\t\t.Power = {move['power']}, .Accuracy = {move['accuracy']},\n",
                "\t},\n",
            ])
        f.writelines([
            "}};\n",
            '\n',
        ])
        for i, move in enumerate(moves):
            name = move['name'].upper().replace(' ', '_')
            f.writelines([
                f"const MoveInfo* MOVE_{name}",
                ' ' * (move_name_len + 1 - len(move['name'])),
                f"= &POKEMON_MOVES[{i}];\n"
            ])


def write_species_header(input_path: Path, output_file: Path) -> None:
    """"""
    species = []
    species_name_len: int = 0
    for species_file in input_path.glob("*.json"):
        with species_file.open('r') as f:
            species.append(json.load(f))
    with output_file.open('w') as f:
        f.writelines([
            "#pragma once\n",
            "#include <array>\n",
            "#include <string>\n",
            "#include \"pokemon.hpp\"\n",
            '\n',
            f"constexpr size_t SPECIES_COUNT = {len(species)};\n"
            "const std::array<const PokemonInfo, SPECIES_COUNT> POKEMON_SPECIES = {{\n"
        ])
        for species_ in species:
            if len(species_['name']) > species_name_len:
                species_name_len = len(species_['name'])
            element_1: str = species_['type'][0]
            element_2: str = species_['type'][1] if len(species_['type']) == 2 else element_1
            f.writelines([
                "\t{\n",
                f"\t\t.Name = \"{species_['name']}\",\n"
                f"\t\t.Elements = {{{{ ElementType::{element_1}, ElementType::{element_2} }}}},\n"
                "\t},\n",
            ])
        f.writelines([
            "}};\n",
            '\n',
        ])
        for i, species_ in enumerate(species):
            name = species_['name'].upper().replace(' ', '_')
            f.writelines([
                f"const PokemonInfo* SPECIES_{name}",
                ' ' * (species_name_len + 1 - len(species_['name'])),
                f"= &POKEMON_SPECIES[{i}];\n"
            ])


## Body
#write_element_header(TYPE_CHART_INPUT, TYPE_CHART_OUTPUT)
write_moves_header(POKEMON_MOVE_INPUT, POKEMON_MOVE_OUTPUT)
#write_species_header(POKEMON_SPECIES_INPUT, POKEMON_SPECIES_OUTPUT)
