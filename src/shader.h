#ifndef SHADER_H
#define SHADER_H

#include "file-manager.h"

enum E_ShaderType {
  VERTEX,
  FRAGMENT,
  PROGRAM
};

typedef struct Shader {
  enum E_ShaderType type;
  int id; 
} Shader;

Shader Shader_Create(enum E_ShaderType shaderType, FileManager* fileManager, char* path);
int Shader_ErrorCheck(Shader shader);
Shader Shader_Link(Shader vertex, Shader frag);

#endif
