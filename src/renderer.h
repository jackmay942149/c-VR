#ifndef RENDERER_H
#define RENDERER_H

#include "color.h"

typedef struct Renderer {
  int width;
  int height;
  ColorBuffer* data;
} Renderer;

Renderer Renderer_Init(int width, int height);
void Renderer_Update(const Renderer renderer);
void Renderer_Quit(Renderer* renderer);
#endif
