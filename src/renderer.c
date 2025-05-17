#include <stdlib.h>
#include "renderer.h"
#include "color.h"

Renderer Renderer_Init(int width, int height) {
  ColorBuffer* cb = (ColorBuffer*) malloc(sizeof(ColorBuffer) + width * height * sizeof(Color3i));
  cb->size = width * height;
  Renderer r = {.width = width, .height = height, .data = cb};
  return r;
}

void Renderer_Update(const Renderer renderer) {
  for (int j = renderer.height-1; j>=0; j--) {
    for (int i = 0; i < renderer.width; i++) {
      Color3f color = {(float)i / (float)renderer.width, (float)j / (float)renderer.height, 0.2f};
      Color_Multiply(&color, 255.99f); // Adjust this I don't like the reference pass
      Color3i adjustedColor = Color_Convert(&color); // Same here
      int index = (renderer.height - 1 - j)*renderer.width + i;
      renderer.data->buffer[index] = adjustedColor;
    }
  }
}

void Renderer_Quit(Renderer* renderer) {
  free(renderer->data);
  renderer->data = NULL;
}
