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

  Shader s = {.type = shaderType, .id = shaderId };
  Shader_ErrorCheck(s);
  
  free(shaderData);
  shaderData = NULL;

  return s;
}

void Shader_ErrorCheck(Shader shader){
  int success;
  char infoLog[512];

  if (shader.type == PROGRAM){
    glGetProgramiv(shader.id, GL_LINK_STATUS, &success);
    glGetProgramInfoLog(shader.id, 512, NULL, infoLog);
  } else {
    glGetShaderiv(shader.id, GL_COMPILE_STATUS, &success);
    glGetShaderInfoLog(shader.id, 512, NULL, infoLog);
  }
  
  if (!success){
    printf("Error shader compilation failed:");
    printf(infoLog);
    exit(1);
  }
  return;
}

Shader Shader_Link(Shader vertex, Shader frag) {
  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertex.id);
  glAttachShader(shaderProgram, frag.id);
  glLinkProgram(shaderProgram);

  Shader s = {PROGRAM, shaderProgram};
  Shader_ErrorCheck(s);

  return s;
}
