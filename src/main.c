#include <stdlib.h>
#include "file-manager.h"
#include "math/math.c"
#include "renderer.h"
#include "shader.h"
#include "glad.h"
#include "glfw3.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main(void){
  // Add file loader
  FileManager fileManager = FileManager_Init();

  // Window Abstraction
  
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
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  
  // Initialize GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
      printf("Failed to initialize GLAD");
      return -1;
  }

  glViewport(0, 0, 800, 600);
  
  // scene abstraction
  // scene is array of objects
  // object has vertices, vao, vbo, shaderprogram
  // make object abstraction first do window before that

  // Set vertex data
  float vertices[] = {
     0.5f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f
  };

  unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
  };

  // Initialize VAO
  unsigned int VAO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);


  // Initialize VBO
  unsigned int VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Initialise EBO
  unsigned int EBO;
  glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
  
  Shader vertShader = Shader_Create(VERTEX, &fileManager, "../res/default.vert");
  Shader fragShader = Shader_Create(FRAGMENT, &fileManager, "../res/default.frag");
  Shader linkShader = Shader_Link(vertShader, fragShader);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glUseProgram(linkShader.id);
  glDeleteShader(vertShader.id);
  glDeleteShader(fragShader.id);

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glUseProgram(linkShader.id);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  
  /* Software Renderer Logic
  Renderer renderer = Renderer_Init(20, 10);
  Renderer_Update(renderer);
  
  File file = FileManager_OpenFile(&fileManager, "../res/output.ppm");
  FileManager_WriteRendererToPPM(file, renderer);
  */

  FileManager_CloseAll(&fileManager);

  //Renderer_Quit(&renderer);
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
} 
