#ifndef APPLICATION_H
#define APPLICATION_H

#include "glad.h"
#include "glfw3.h"

typedef struct Application {
  GLFWwindow* window;
  int width;
  int height;
  int isRunning;
} Application ;

Application Application_Start(int width, int height);
void Application_Update(Application* app);
void Application_Close(Application* app);

#endif
