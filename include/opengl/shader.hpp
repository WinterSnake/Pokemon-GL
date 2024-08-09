/*
	PokemonGL
	- [OpenGL]Shader

	Written By: Ryan Smith
*/
#pragma once
#ifndef _OPENGL_SHADER_H
#define _OPENGL_SHADER_H

#include <stdint.h>
#include <string>

class Shader
{
	public:
		Shader(const std::string&, const std::string&);
	public:
		void Start();
		void End();
		uint32_t Id;
};

#endif
