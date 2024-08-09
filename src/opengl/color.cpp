/*
	PokemonGL
	- [OpenGL]Color

	Written By: Ryan Smith
*/

#include "opengl/color.hpp"

// Constructors
Color::Color(uint8_t r, uint8_t g, uint8_t b) : R(r), G(g), B(b), A(255) { }
Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : R(r), G(g), B(b), A(a) { }

std::array<const float, 4> Color::Normalize()
{
	return {
		(float)R / 255.0f,
		(float)G / 255.0f,
		(float)B / 255.0f,
		(float)A / 255.0f,
	};
}
