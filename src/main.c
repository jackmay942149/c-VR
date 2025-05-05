#include "file-manager.h"
#include "math/math.c"
#include "renderer.h"
#include "glad.h"
#include "glfw3.h"

int main(void){

  // Initialize GLFW
  glfwInit();  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Initialize window need to initialize glad before this
  GLFWwindow* window = glfwCreateWindow(800, 600, "c-VR", NULL, NULL);
  if (window == NULL) {
    printf("Failed to create GLFW window");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  // Initialize GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
      printf("Failed to initialize GLAD");
      return -1;
  }

  glViewport(0, 0, 800, 600);

  while (!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
    
  Renderer renderer = Renderer_Init(20, 10);
  Renderer_Update(renderer);
  
  FileManager fileManager = FileManager_Init();
  File file = FileManager_OpenFile(&fileManager, "res/output.ppm");
  FileManager_WriteRendererToPPM(file, renderer);
  FileManager_CloseAll(&fileManager);

  Renderer_Quit(&renderer);
}
