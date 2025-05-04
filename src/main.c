#include <stdio.h>
#include "color.c"
#include "file-manager.c"
#include "math/math.c"
#include "math/vector.h"

int main(void){
  Vec2f AF1 = {3.0, 4.0};
  Vec2f AF2 = {2.0, -1.0};
  float AFR = Vec2f_Dot(AF1, AF2);
  printf("Result: %f\n", AFR);
  
  Vec3f BF1 = {1, 0, -2};
  Vec3f BF2 = {-3, 5, 1};
  float BFR = Vec3f_Dot(BF1, BF2);
  printf("Result: %f\n", BFR);
  
  Vec4f CF1 = {0, 2, 1, -1};
  Vec4f CF2 = {4, -1, 3, 2};
  float CFR = Vec4f_Dot(CF1, CF2);
  printf("Result: %f\n", CFR);
}
  /* File Manager Test Stuff
  
  FileManager fileManager = FileManager_Init();
  int nx = 20;
  int ny = 10;

  FILE* file = FileManager_OpenFile(&fileManager, "res/output.ppm");
  
  fprintf(file, "P3\n");
  fprintf(file, "%i %i\n255\n", nx, ny);

  for(int j=ny-1; j>=0; j--) {
    for (int i=0; i < nx; i++) {
      Color3f color = {(float)i / (float)nx, (float)j / (float)ny, 0.2};
      Color_Multiply(&color, 255.99);
      Color3i adjustedColor = Color_Convert(&color);
      fprintf(file, "%i %i %i\n", adjustedColor.r, adjustedColor.g, adjustedColor.b);      
    }
  }

  FileManager_CloseAll(&fileManager);
  */
