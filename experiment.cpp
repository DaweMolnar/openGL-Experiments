#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

using namespace glm;

int main()
{
	if(!glfwInit()) {
		std::cout << "Init failed" << std::endl;
		std::exit(-1);
	}
	glfwWindowHint(GLFW_SAMPLES, 4); //4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //use opengl 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // to run on macos
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //dont want the old opengl (TODO check what it means)
	GLFWwindow* window;
	window = glfwCreateWindow(1024,768, "Experiment", nullptr, nullptr);
	if(window == nullptr) {
		std::cout << "Failed to open GLFW window" << std::endl;
		glfwTerminate();
		std::exit(-1);
	}
	glfwMakeContextCurrent(window); //init glew
	glewExperimental=true;
	if(glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize glew" << std::endl;
		std::exit(-1);
	}
	glfwSetInputMode(window,GLFW_STICKY_KEYS, GL_TRUE);
	do {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	while(glfwGetKey(window,GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
	std::exit(0);
}
