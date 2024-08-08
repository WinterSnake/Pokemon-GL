/*
	PokemonGL
	Written By: Ryan Smith
*/
#include <iostream>
#include <string>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

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

	// GLFW: Loop
	while (!glfwWindowShouldClose(window))
	{
		/* Events */
		glfwPollEvents();
		/* Rendering */
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}

	// GLFW: Close
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
