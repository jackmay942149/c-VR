#ifndef ARRAY_H
#define ARRAY_H
typedef struct Array {
  void* data;
  int elementSize;
  int count;
  int capacity;
} Array;

Array Array_Create(int elementSize, int capacity);
void Array_Insert(Array* array, void* elem);
void* Array_At(Array* array, int location);
void Array_InsertAt(Array* array, void* elem, int location);
void Array_ForEach(Array* array, void (*func)(void*));
void Array_Destroy(Array* array);
#endif
