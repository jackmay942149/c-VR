#ifndef STACK_H
#define STACK_H
#include "array.h"
typedef struct Stack {
  void* data;
  int elementSize;
  int count;
  int capacity;
} Stack;

Stack Stack_Create(int elementSize, int capacity);
void Stack_Push(Stack* stack, void* elem);
void* Stack_Pop(Stack* stack);
void* Stack_Peek(Stack* stack);
void Stack_ForEach(Stack* stack, void (*func)(void*));
Array Stack_ToArray(Stack* stack);
void Stack_Destroy(Stack* stack);
#endif
