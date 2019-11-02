#include <GL/glew.h>
#include <iostream>
#include <GLFW/glfw3.h>

int main(){

		if(!glfwInit()) exit(EXIT_FAILURE);

		/* Settings options */
		/* 4x antialiasing */
		glfwWindowHint(GLFW_SAMPLES, 4);

		/* Set version OpenGL 4.3*/
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		/* Focus only new version OpenGL */
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		/* Windows settings */
		glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		/* Create window */
		GLFWwindow* window = glfwCreateWindow(1024, 786, "Game", NULL, NULL);

		if(window == NULL){
				std::cerr << "Failed to create OpenGL window\n";
				glfwTerminate();

				exit(EXIT_FAILURE);
		}

		glfwMakeContextCurrent(window);
		glewExperimental = true;

		if(glewInit() != GLEW_OK){
				std::cerr << "Failed to initalize GLEW\n";

				exit(EXIT_FAILURE);
		}

		glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

		do{
				glClear(GL_COLOR_BUFFER_BIT);

				glfwSwapBuffers(window);
				glfwPollEvents();
		} while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

		return 0;
}
