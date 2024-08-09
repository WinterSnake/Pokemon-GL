/*
	PokemonGL
	Written By: Ryan Smith
*/
#include <iostream>
#include <string>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "opengl.hpp"

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	// GLFW: Initialize
	if (!glfwInit())
	{
		std::cerr << "Unable to init GLFW.\n";
		return 1;
	}
	// GLFW: Window Options
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
	glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_NATIVE_CONTEXT_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	// GLFW: Create Window
	GLFWwindow* window = glfwCreateWindow(1920, 1080, "PokemonGL", NULL, NULL);
	if (!window)
	{
		std::cerr << "Unable to create a GLFW window.\n";
		glfwTerminate();
		return 1;
	}

	// GLFW: OpenGL
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	// OpenGL: Triangle
	float positions[] = {
		-0.5f, -0.5f,
		 0.0f,  0.5f,
		 0.5f, -0.5f,
	};
	uint32_t vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// GLFW: Loop
	while (!glfwWindowShouldClose(window))
	{
		/* Rendering */
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);
		/* Events */
		glfwPollEvents();
	}

	// GLFW: Close
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
