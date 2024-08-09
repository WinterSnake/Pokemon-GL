/*
	PokemonGL
	- [OpenGL]Shader

	Written By: Ryan Smith
*/
#include "glad/glad.h"

#include "opengl/shader.hpp"

static GLuint CompileOpenGLShader(GLenum type, const std::string& source)
{
	// TODO: Error handling
	GLuint shaderId = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(shaderId, 1, &src, nullptr);
	glCompileShader(shaderId);
	return shaderId;
}

Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource)
{
	// TODO: Handle errors
	GLuint vertexId   = CompileOpenGLShader(GL_VERTEX_SHADER,   vertexSource);
	GLuint fragmentId = CompileOpenGLShader(GL_FRAGMENT_SHADER, fragmentSource);
	// Create program
	Id = glCreateProgram();
	glAttachShader(Id, vertexId);
	glAttachShader(Id, fragmentId);
	glLinkProgram(Id);
	glValidateProgram(Id);
	// Cleanup shaders
	glDeleteShader(vertexId);
	glDeleteShader(fragmentId);
}

void Shader::Start()
{
	glUseProgram(Id);
}

void Shader::End()
{

}
