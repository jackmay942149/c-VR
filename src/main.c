#include "file-manager.h"
#include "math/math.c"
#include "renderer.h"

int main(void){

  Renderer renderer = Renderer_Init(20, 10);
  Renderer_Update(renderer);
  
  FileManager fileManager = FileManager_Init();
#ifdef _MSC_VER
  File file = FileManager_OpenFile(&fileManager, "res/output.ppm");
#else
  File file = FileManager_OpenFile(&fileManager, "res/output.ppm");
#endif

  FileManager_WriteRendererToPPM(file, renderer);
  FileManager_CloseAll(&fileManager);

  Renderer_Quit(&renderer);
}
