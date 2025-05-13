#include "application.h"
#include "glfw3.h"
#include <stdlib.h>
#include <stdio.h>

static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    
}

Application Application_Start(int width, int height) {
  // Initialize GLFW
  glfwInit();  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Initialize window need to initialize glad before this
  GLFWwindow* window = glfwCreateWindow(width, height, "c-VR", NULL, NULL);
  if (window == NULL) {
    printf("Failed to create GLFW window");
    glfwTerminate();
    exit(1);
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  
  // Initialize GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
      printf("Failed to initialize GLAD");
  }

  glViewport(0, 0, 800, 600);
  Application app = {.window = window, .width = width, .height = height, .isRunning = 1};
  return app; 
}

void Application_Update(Application* app) {
  glfwSwapBuffers(app->window);
  glfwPollEvents();
  app->isRunning = !glfwWindowShouldClose(app->window);
}

void Application_Close(Application* app) {
  glfwTerminate();
  app->window = NULL;
}
