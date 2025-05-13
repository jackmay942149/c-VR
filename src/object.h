#ifndef OBJECT_H
#define OBJECT_H

#include "shader.h"

typedef struct Object {
  float *vertices;
  unsigned int *indicies;
  unsigned int iCount;
  unsigned int VAO;
  unsigned int VBO;
  unsigned int EBO;
  Shader shaderProgram;
} Object;

Object Object_StackAllocate(
  float *vertices,
  unsigned int vCount,
  unsigned int *indicies,
  unsigned int iCount,
  Shader shaderProgram); 

#endif
