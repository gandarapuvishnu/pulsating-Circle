#include "Setup.h"

#include <iostream>

//Setup GLFW, GLEW successfully
GLFWwindow* setup()
{
    bool success = true;

    /* Initialize the library */
    if (glfwInit() != GLFW_TRUE)
    {
        std::cout << "GLFW Initialisation failed." << std::endl;
        success = false;        
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
    if (!window)
    {
        std::cout << "OpenGL context window failed." << std::endl;
        glfwTerminate();
        success = false;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //Synchronisation of fps
    glfwSwapInterval(1);

    //GLFW current context created!

    glewExperimental = GL_TRUE;
    //Modern OpenGL 
    //GLEW has to be initialised after a proper context window has been created.
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Error Initialising GLEW" << std::endl;
        success = false;
    }

    std::cout << "GL_VERSION: " << glGetString(GL_VERSION) << std::endl;

    if (success)
        return window;
    else
        return 0;
}