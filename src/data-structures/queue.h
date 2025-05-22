#ifndef QUEUE_H
#define QUEUE_H
#include "array.h"

typedef struct Queue {
  void* data;
  int elementSize;
  int headIndex;
  int tailIndex;
  int capacity;
} Queue;

Queue Queue_Create(int elementSize, int capacity);
void Queue_Push(Queue* queue, void* elem);
void* Queue_Pop(Queue* queue);
void* Queue_Peek(Queue* queue);
void Queue_ForEach(Queue* queue, void (*func)(void*));
Array Queue_ToArray(Queue* queue);
void Queue_Destroy(Queue* queue);

#endif
