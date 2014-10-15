#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

using namespace glm;

int main()
{
	if(!glfwInit()) {
		std::cout << "Init failed" << std::endl;
		std::exit(-1);
	}
	std::exit(0);
}
