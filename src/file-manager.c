#include "file-manager.h"

FileManager FileManager_Init() {
 FileManager f = {.count = 0};
 return f;
}

void FileManager_CloseAll(FileManager* fileManager) {
  for (int i = 0; i < fileManager->count; i++){
    fclose(fileManager->files[i].file);
  }
}

FILE* FileManager_OpenFile(FileManager* fileManager, char* path) {
  FILE* osFile;
  osFile = fopen(path, "w");

  fseek(osFile, 0, SEEK_END);
  File file = {.file = osFile, .sizeBytes = ftell(osFile)};
  fileManager->files[fileManager->count] = file;
  fileManager->count++;
  fseek(osFile, 0, SEEK_SET);
  return osFile;
}
