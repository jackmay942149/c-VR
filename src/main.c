#include "application.h"
#include "file-manager.h"
#include "glfw3.h"
#include "math/matrix.h"
#include "math/vector.h"
#include "object.h"
#include "shader.h"
#include "data-structures/array.h"
#include "glad.h"

int main(void){
  Array a = Array_Create(sizeof(int), 5);
  Array_Destroy(&a);

  Array b = Array_Create(sizeof(int), 2);
  int x = 1;
  int y = 2;
  int z = 3;
  Array_Insert(&b, (void*) &x);
  Array_Insert(&b, (void*) &y);
  Array_Insert(&b, (void*) &z);
  int w = *(int*) Array_At(&b, 0);
  printf("printing w = %i", w);
}


/*  Engine Logic. Postponing this to practice data structures. Would like to
    work on a simplification of this main function as well
      
int main(void){
  // Add file loader
  FileManager fileManager = FileManager_Init();

  // Window Abstraction
  Application application = Application_Start(800, 600);
  
  // scene abstraction
  // scene is array of objects

  // Set vertex data
  float vertices[] = {
     0.5f,  0.5f,  0.5f, // 0 Right, Top, Back
     0.5f, -0.5f,  0.5f, // 1 Right, Bottom, Back
    -0.5f, -0.5f,  0.5f, // 2 Left, Bottom, Back
    -0.5f,  0.5f,  0.5f, // 3 Left, Top, Back
     0.5f,  0.5f, -0.5f, // 4 Right, Top, Front
     0.5f, -0.5f, -0.5f, // 5 Right, Bottom, Front
    -0.5f, -0.5f, -0.5f, // 6 Left, Bottom, Front
    -0.5f,  0.5f, -0.5f  // 7 Left, Top, Front
  };

  unsigned int indices[] = {
    0, 1, 2, 0, 2, 3, // Back
    4, 5, 6, 4, 6, 7, // Front
    0, 1, 4, 1, 4, 5, // Right
    2, 3, 6, 3, 6, 7, // Left
    0, 3, 4, 3, 4, 7, // Top
    1, 2, 5, 2, 5, 6  // Bottom
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glUseProgram(o1.shaderProgram.id);
    Mat4f transform = Mat4f_Identity();
    Vec3f rotAxis = {.x = 0, .y = 1, .z = 0};
    Mat4f_Rotate(&transform, 120.0f * (float) glfwGetTime(), rotAxis);

    Mat4f view = Mat4f_Identity();
    Vec3f camTranslation = {.x = 0, .y = -3, .z = -10};
    Mat4f_Translate(&view, camTranslation);
    Mat4f projection = Mat4f_Perspective(45.0f, 800.0f/600.0f, 0.1f, 100.0f);

  
    unsigned int modelLoc = glGetUniformLocation(o1.shaderProgram.id, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_TRUE, (float*) &transform);
    unsigned int viewLoc = glGetUniformLocation(o1.shaderProgram.id, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_TRUE, (float*) &view);
    unsigned int projectionLoc = glGetUniformLocation(o1.shaderProgram.id, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_TRUE, (float*) &projection);

      
    glBindVertexArray(o1.VAO);       // foreach object draw
    glDrawElements(GL_TRIANGLES, o1.iCount, GL_UNSIGNED_INT, 0);
    
    Application_Update(&application);
  }

  Application_Close(&application);
}
*/


  /* Software Renderer Logic
  Renderer renderer = Renderer_Init(20, 10);
  Renderer_Update(renderer);
  
  File file = FileManager_OpenFile(&fileManager, "../res/output.ppm");
  FileManager_WriteRendererToPPM(file, renderer);
  

  FileManager_CloseAll(&fileManager);

  Renderer_Quit(&renderer);
  */
