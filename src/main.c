#include "application.h"
#include "file-manager.h"
#include "glfw3.h"
#include "math/matrix.h"
#include "math/vector.h"
#include "object.h"
#include "shader.h"
#include "glad.h"

int main(void){
  // Add file loader
  FileManager fileManager = FileManager_Init();

  // Window Abstraction
  Application application = Application_Start(800, 600);
  
  // scene abstraction
  // scene is array of objects

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

  Shader vertShader = Shader_Create(VERTEX, &fileManager, "../res/default.vert");
  Shader fragShader = Shader_Create(FRAGMENT, &fileManager, "../res/default.frag");
  Shader linkShader = Shader_Link(vertShader, fragShader);
  glUseProgram(linkShader.id);
  glDeleteShader(vertShader.id);
  glDeleteShader(fragShader.id);

  FileManager_CloseAll(&fileManager);

  Object o1 = Object_StackAllocate(
    vertices, sizeof(vertices),
    indices, sizeof(indices),
    linkShader);


  while (application.isRunning) { // application running
    glClear(GL_COLOR_BUFFER_BIT);
    
    glUseProgram(o1.shaderProgram.id);
    Mat4f transform = Mat4f_Identity();
    Vec3f rotAxis = {.x = 0, .y = 0, .z = 1};
    Mat4f_Rotate(&transform, (float) glfwGetTime(), rotAxis);

  
    unsigned int transformLoc = glGetUniformLocation(o1.shaderProgram.id, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, (float*) &transform);  
    glBindVertexArray(o1.VAO);       // foreach object draw
    glDrawElements(GL_TRIANGLES, o1.iCount, GL_UNSIGNED_INT, 0);
    
    Application_Update(&application);
  }

  Application_Close(&application);
}


  /* Software Renderer Logic
  Renderer renderer = Renderer_Init(20, 10);
  Renderer_Update(renderer);
  
  File file = FileManager_OpenFile(&fileManager, "../res/output.ppm");
  FileManager_WriteRendererToPPM(file, renderer);
  

  FileManager_CloseAll(&fileManager);

  Renderer_Quit(&renderer);
  */
