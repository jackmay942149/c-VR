#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#define MAX_FILES 10
#include <stdio.h>
#include "renderer.h"

typedef struct File {
  FILE* file;
  long sizeBytes;
} File;

typedef struct FileManager {
  File files[MAX_FILES];
  int count;
} FileManager;

FileManager FileManager_Init();
void FileManager_CloseAll(FileManager* fileManager);
File FileManager_OpenFile(FileManager* fileManger, char* path);
void FileManager_WriteRendererToPPM(File file, Renderer renderer);

#endif
