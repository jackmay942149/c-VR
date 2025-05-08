#include <stdlib.h>
#include "file-manager.h"
#include "math/math.c"
#include "renderer.h"
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

  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
  };

  unsigned int VAO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);


  // Initialize VBO
  unsigned int VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Compile Vertex Shader
  File vertexShaderSrc = FileManager_OpenFile(&fileManager, "../res/default.vert");

  char* vertexShaderData = (char*)malloc(vertexShaderSrc.sizeBytes + 1);
  if (!vertexShaderData) {
      fprintf(stderr, "Memory allocation failed.\n");
      exit(1);
  }

  // Read and null-terminate
  fread(vertexShaderData, 1, vertexShaderSrc.sizeBytes, vertexShaderSrc.file);
  vertexShaderData[vertexShaderSrc.sizeBytes] = '\0';
  
  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER); 
  glShaderSource(vertexShader, 1, &vertexShaderData, NULL);
  glCompileShader(vertexShader);

  int  success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

  if (!success)
  {
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
  }

  free(vertexShaderData);
  vertexShaderData = NULL;

  // Compile Frag Shader
  File fragShaderSrc = FileManager_OpenFile(&fileManager, "../res/default.frag");

  char* fragShaderData = (char*)malloc(fragShaderSrc.sizeBytes + 1);
  if (!fragShaderData) {
      fprintf(stderr, "Memory allocation failed.\n");
      exit(1);
  }

  // Read and null-terminate
  fread(fragShaderData, 1, fragShaderSrc.sizeBytes, fragShaderSrc.file);
  fragShaderData[fragShaderSrc.sizeBytes] = '\0';

  unsigned int fragShader;
  fragShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragShader, 1, &fragShaderData, NULL);
  glCompileShader(fragShader);

  glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);

  if (!success)
  {
      glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
      printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
  }

  free(fragShaderData);
  fragShaderData = NULL;

  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragShader);
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
  glDeleteShader(vertexShader);
  glDeleteShader(fragShader);



  while (!glfwWindowShouldClose(window)) {
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  
    
  Renderer renderer = Renderer_Init(20, 10);
  Renderer_Update(renderer);
  
  File file = FileManager_OpenFile(&fileManager, "../res/output.ppm");
  FileManager_WriteRendererToPPM(file, renderer);
  FileManager_CloseAll(&fileManager);

  Renderer_Quit(&renderer);
}
