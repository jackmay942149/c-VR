#include "array.h"
#include <stdio.h>
#include <string.h> // for memcpy
#include <stdlib.h>

Array Array_Create(int elementSize, int capacity){
  Array a;
  void* ptr = malloc(capacity * elementSize);
  if (ptr == NULL) {
    printf("OOM Error\n");
    exit(1);
  }
  
  a.data = ptr;
  a.elementSize = elementSize;
  a.count = 0;
  a.capacity = capacity;

  printf("Created an array of %i that have a individual size of %i, and is located at %p\n", a.capacity, a.elementSize, a.data);
  return a;
}

static void Array_Realloc(Array *array){
    void* ptr = realloc(array->data, array->elementSize * array->capacity * 2);
    if (ptr == NULL){
      printf("OOM Error\n");
      exit(1);
    }
    array->data = ptr;
    array->capacity *= 2;
    printf("Reallocated area to hold %i bytes\n", array->capacity * array->elementSize);
}

void Array_Insert(Array *array, void* elem){
  if (array->count == array->capacity){
    Array_Realloc(array);
  }
  void* insertLocation = (char*) array->data + array->count * array->elementSize;
  memcpy(insertLocation, elem, array->elementSize);
  array->count++;
}

void* Array_At(Array *array, int location){
  if (location > array->count){
    printf("Attempting to access array at index: %i, when it has a count of %i", location, array->count);
    return NULL;
  }
  return (char*) array->data + array->elementSize * location;
}

void Array_InsertAt(Array* array, void *elem, int location){
  if (location >= array->count) {
    Array_Insert(array, elem);
    return;
  }
  if (array->count == array->capacity){
    Array_Realloc(array);
  }
  for (int i = array->count; i > location; i--) {
    void* insertLocation = (char*) array->data + i * array->elementSize;
    memcpy(insertLocation, Array_At(array, i-1), array->elementSize);
  }
  void* insertLocation = (char*) array->data + location * array->elementSize;
  memcpy(insertLocation, elem, array->elementSize);
  array->count++;
}

void Array_ForEach(Array *array, void (*func)(void *)){
  for (int i = 0; i < array->count; i++) {
    void* location = (char*) array->data + i * array->elementSize;
    func(location);
  }  
}

void Array_Destroy(Array *array){
  free(array->data);
  array->data = NULL;
  printf("Freed Array\n");
}
