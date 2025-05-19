#include "stack.h"
#include "array.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Stack Stack_Create(int elementSize, int capacity){
  void* ptr = malloc(capacity * elementSize);
  assert(ptr != NULL);
  Stack s = {
    s.data = ptr,
    s.elementSize = elementSize,
    s.count = 0,
    s.capacity = capacity
  };
  printf("Created stack on heap at location: %p\n", s.data);
  return s;
}

static void Stack_Realloc(Stack* stack){
  assert(stack->data != NULL);
  void* ptr = realloc(stack->data, stack->elementSize * stack->capacity * 2);
  assert(ptr != NULL);
  stack->data = ptr;
  stack->capacity *= 2;
  printf("Reallocated stack to fit %i bytes\n", stack->capacity * stack->elementSize);
  return;
}

void Stack_Push(Stack* stack, void* elem){
  assert(stack->data != NULL);
  if (stack->count == stack->capacity){
    Stack_Realloc(stack);
  }
  void* insertLocation = (char*) stack->data + stack->count * stack->elementSize;
  memcpy(insertLocation, elem, stack->elementSize);
  stack->count++;
  printf("Pushed onto the stack, which now holds %i elems\n", stack->count);
  return;
}

void* Stack_Pop(Stack* stack){
  void* readLocation = Stack_Peek(stack);
  stack->count--;
  return readLocation;  
}

void* Stack_Peek(Stack* stack){
  assert(stack->data != NULL);
  assert(stack->count > 0);
  void* readLocation = (char*) stack->data + (stack->count-1) * stack->elementSize;
  return readLocation;  
};

void Stack_ForEach(Stack* stack, void (*func)(void*)){
  assert(stack->data != NULL);
  for (int i = stack->count; i > 0; i--){
    void* location = (char*) stack->data + (i-1) * stack->elementSize;
    func(location);
  }
  return;
}

Array Stack_ToArray(Stack* stack){
  assert(stack->data != NULL);
  Array a = Array_Create(stack->elementSize, stack->capacity);
  memcpy(a.data, stack->data, stack->elementSize * stack->count);
  a.count = stack->count;
  return a;
}

void Stack_Destroy(Stack* stack){
  free(stack->data);
  stack->data = NULL;
  printf("Freed Stack\n");
  return;
}
