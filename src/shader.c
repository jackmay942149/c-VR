#include "shader.h"
#include "file-manager.h"
#include "glad.h"
#include <stdlib.h>

Shader Shader_Create(enum E_ShaderType shaderType, FileManager* fileManager, char* path) {
  File shaderSrc = FileManager_OpenFile(fileManager, path);
  char* shaderData = (char*) malloc(shaderSrc.sizeBytes + 1);

  if (!shaderData) {
    printf("ERROR: shader %s memeory allocation failed", path);
    exit(1);
  }

  fread(shaderData, 1, shaderSrc.sizeBytes, shaderSrc.file);
  shaderData[shaderSrc.sizeBytes] = '\0';

  unsigned int shaderId;

  if (shaderType == VERTEX){
    shaderId = glCreateShader(GL_VERTEX_SHADER);
  } else if (shaderType == FRAGMENT){
    shaderId = glCreateShader(GL_FRAGMENT_SHADER);
  }

  glShaderSource(shaderId, 1, &shaderData, NULL);
  glCompileShader(shaderId);

  free(shaderData);
  shaderData = NULL;

  Shader s = {.type = shaderType, .id = shaderId };
  return s;
}


int Shader_ErrorCheck(Shader shader);
Shader Shader_Link(Shader vertex, Shader frag);
