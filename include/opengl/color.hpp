/*
	PokemonGL
	- [OpenGL]Color

	Written By: Ryan Smith
*/
#pragma once
#ifndef _OPENGL_COLOR_H
#define _OPENGL_COLOR_H

#include <stdint.h>
#include <array>

struct Color
{
	public:
		Color(uint8_t, uint8_t, uint8_t);
		Color(uint8_t, uint8_t, uint8_t, uint8_t);
	public:
		std::array<const float, 4> Normalize();
	public:
		uint8_t R;
		uint8_t G;
		uint8_t B;
		uint8_t A;
};

#endif
