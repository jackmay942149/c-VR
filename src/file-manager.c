#include "file-manager.h"
#include "stdlib.h"
#include <corecrt.h>

FileManager FileManager_Init() {
 FileManager f = {.count = 0};
 return f;
}

void FileManager_CloseAll(FileManager* fileManager) {
  for (int i = 0; i < fileManager->count; i++){
    fclose(fileManager->files[i].file);
  }
}

File FileManager_OpenFile(FileManager* fileManager, char* path) {
  FILE* osFile;
  errno_t err = fopen_s(&osFile, path, "rb+");
  if (err != 0) {
    printf("Errored on file manager open file");
    exit(1);
  }

  if (osFile == NULL) {
      printf("Error Loading File");
      exit(1);
  }
  else {
      fseek(osFile, 0, SEEK_END);
      long fileLength = ftell(osFile);
      File file = { .file = osFile, .sizeBytes = fileLength };
      fileManager->files[fileManager->count] = file;
      fileManager->count++;
      fseek(osFile, 0, SEEK_SET);
      return file;
  }
}

void FileManager_WriteRendererToPPM(File file, Renderer renderer) {
  fprintf(file.file, "P3\n");
  fprintf(file.file, "%i %i\n255\n", renderer.width, renderer.height);

  for(int i = 0; i < renderer.data->size; i++) {
      Color3i color = renderer.data->buffer[i];
      fprintf(file.file, "%i %i %i\n", color.r, color.g, color.b);
  }
} 
