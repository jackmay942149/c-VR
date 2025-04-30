#include <stdio.h>
#include "color.h"

int main(void){
  FILE* file;
  int nx = 20;
  int ny = 10;

  file = fopen("res/output.ppm", "w");
  fprintf(file, "P3\n");
  fprintf(file, "%i %i\n255\n", nx, ny);

  for(int j=ny-1; j>=0; j--){
    for (int i=0; i < nx; i++){
      Color3f color = {(float)i / (float)nx, (float)j / (float)ny, 0.2};
      Color_Multiply(&color, 255.99);
      Color3i adjustedColor = Color_Convert(&color);
      fprintf(file, "%i %i %i\n", adjustedColor.r, adjustedColor.g, adjustedColor.b);      
    }
  }
  
  fclose(file);
}
