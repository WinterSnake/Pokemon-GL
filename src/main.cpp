/*
	PokemonGL
	Written By: Ryan Smith
*/
#include <iostream>
#include <string>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "opengl.hpp"

#define WIDTH 1920
#define HEIGHT 1080

int main(int argc, const char** argv)
{
	(void)argc;
	(void)argv;

	// GLFW: Initialize
	if (!glfwInit())
	{
		fprintf(stderr, "Unable to init GLFW.\n");
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
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "PokemonGL", NULL, NULL);
	if (!window)
	{
		fprintf(stderr, "Unable to create a GLFW window.\n");
		glfwTerminate();
		return 1;
	}

	// GLFW: OpenGL
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	// OpenGL: Buffers
	GLfloat vertices[] =
	{
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f,  0.5f,
	};

	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// OpenGL: Shader
	const std::string vertShader =
	"#version 400 core\n"
	"in vec4 position;\n"
	"void main() {\n"
	"\tgl_Position = position;\n"
	"}\n";
	const std::string fragShader =
	"#version 400 core\n"
	"out vec4 FragColor;\n"
	"void main() {\n"
	"\tFragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
	"}\n";
	Shader triangleShader = Shader(vertShader, fragShader);
	triangleShader.Start();


	// GLFW: Loop
	while (!glfwWindowShouldClose(window))
	{
		/* Rendering */
		// Clear
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// Triangle
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		// Swap Buffer
		glfwSwapBuffers(window);
		/* Events */
		glfwPollEvents();
		int escapeKeyState = glfwGetKey(window, GLFW_KEY_ESCAPE);
		if (escapeKeyState == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	// OpenGL: Cleanup
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	// GLFW: Close
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
