#include <stdlib.h>
#include "file-manager.h"
#include "math/math.c"
#include "renderer.h"
#include "shader.h"
#include "glad.h"
#include "glfw3.h"

int main(void){
  // Add file loader
  FileManager fileManager = FileManager_Init();
  
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

  // Set vertex data
  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
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

  // Read shader file and convert to char*
  //
  // TODO: Shader abstraction
  // 
  // Struct: Shader type, int id
  // Create Shader(shader type, &id, &filemanager, path)
  // Error check(shader)
  // Link shader(shader vertex, shade frag)
  Shader vertShader = Shader_Create(VERTEX, &fileManager, "../res/default.vert");

  // Error checking shader compilation
  int  success;
  char infoLog[512];
  glGetShaderiv(vertShader.id, GL_COMPILE_STATUS, &success);

  if (!success)
  {
      glGetShaderInfoLog(vertShader.id, 512, NULL, infoLog);
      printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
  }

  Shader fragShader = Shader_Create(FRAGMENT, &fileManager, "../res/default.frag");

  glGetShaderiv(fragShader.id, GL_COMPILE_STATUS, &success);

  if (!success)
  {
      glGetShaderInfoLog(fragShader.id, 512, NULL, infoLog);
      printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
  }

  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertShader.id);
  glAttachShader(shaderProgram, fragShader.id);
  glLinkProgram(shaderProgram);

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
      glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
      printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
      printf(infoLog);
  }


  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glUseProgram(shaderProgram);
  glDeleteShader(vertShader.id);
  glDeleteShader(fragShader.id);



  while (!glfwWindowShouldClose(window)) {
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  
  /*
  Renderer renderer = Renderer_Init(20, 10);
  Renderer_Update(renderer);
  
  File file = FileManager_OpenFile(&fileManager, "../res/output.ppm");
  FileManager_WriteRendererToPPM(file, renderer);
  */

  FileManager_CloseAll(&fileManager);

  //Renderer_Quit(&renderer);
}
