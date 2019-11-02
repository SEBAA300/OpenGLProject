#include <GLFW/glfw3.h>

class Engine{
		private:
				GLFWwindow* window;

				void initalize();
				void configuration();

		public:
				/* Constructor and Deconstructor */
				Engine();
				~Engine();

				void run();
				void update();
};
