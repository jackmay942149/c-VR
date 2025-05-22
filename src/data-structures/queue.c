#include "queue.h"
#include "array.h"
#include <stdlib.h>
#include <assert.h>

Queue Queue_Create(int elementSize, int capacity) {
  void* ptr = malloc(elementSize * capacity);
  assert(ptr != NULL);
  Queue q = {
    q.data = ptr,
    q.elementSize = elementSize,
    q.capacity = capacity,
    q.headIndex = 0,
    q.tailIndex = 0
  };
  return q;
}

static void* Queue_Realloc(Queue* queue) {
  assert(queue != NULL);
  void* ptr = realloc(queue->data, queue->elementSize * queue->capacity * 2);
  assert(ptr != NULL);
  queue->data = ptr;
  queue->capacity *= 2;

  // TODO: Move data that was at the end to the end
  
}

void Queue_Push(Queue* queue, void* elem) {
  assert(queue->data != NULL);
  if (queue->tailIndex == queue->headIndex - 1) {
    // realloc
  }
  void* insertLocacation
}
void* Queue_Pop(Queue* queue);
void* Queue_Peek(Queue* queue);
void Queue_ForEach(Queue* queue, void (*func)(void*));
Array Queue_ToArray(Queue* queue);

void Queue_Destroy(Queue* queue) {
  free(queue->data);
  queue->data = NULL;
  return;
}
