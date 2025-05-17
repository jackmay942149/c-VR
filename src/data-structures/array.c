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

void Array_Insert(Array *array, void* elem){
  if (array->count == array->capacity) {
    void* ptr = realloc(array->data, array->elementSize * array->capacity * 2);
    if (ptr == NULL){
      printf("OOM Error\n");
      exit(1);
    }
    array->data = ptr;
    array->capacity *= 2;
    printf("Reallocated area to hold %i bytes\n", array->capacity * array->elementSize);
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

void Array_Destroy(Array *array) {
  free(array->data);
  array->data = NULL;
  printf("Freed Array\n");
}
