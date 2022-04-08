#include <iostream>
#include "Adder/adder.h"
#include "GLFW/glfw3.h"
#include <HelloWorldConfig.h>

int main(int argc, char *argv[])
{
    std::cout << argv[0] << " Version " << HELLOWORLD_VERSION_MAJOR << "." << HELLOWORLD_VERSION_MINOR << std::endl;

    std::cout << "Hello World" << std::endl;
    std::cout << add(972.1, 83.9) << std::endl;

    GLFWwindow *window;
    int width, height;

    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(300, 300, "Gears", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Failed to open GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    while (!glfwWindowShouldClose(window))
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    // Exit program
    exit(EXIT_SUCCESS);

    return 0;
}