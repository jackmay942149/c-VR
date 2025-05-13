#include "object.h"
#include "glad.h"


Object Object_StackAllocate(
  float *vertices,
  unsigned int vCount,
  unsigned int *indicies,
  unsigned int iCount,
  Shader shaderProgram) {
   
  // Initialize VAO
  unsigned int VAO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  // Initialize VBO
  unsigned int VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vCount, vertices, GL_STATIC_DRAW);

  // Initialise EBO
  unsigned int EBO;
  glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, iCount, indicies, GL_STATIC_DRAW);

  // Bind data attributes
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  Object o = {
    .vertices = vertices,
    .indicies = indicies,
    .iCount = iCount,
    .VAO = VAO,
    .VBO = VBO,
    .EBO = EBO,
    .shaderProgram = shaderProgram
  };
  return o;
} 
