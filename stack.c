#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

struct stack {
  size_t capacity;
  size_t length;
  size_t data_size;
  void *data;
};

Stack *stack_build(size_t init_cap, size_t data_size) {
  assert(init_cap > 0);
  assert(data_size > 0);

  Stack *stack = malloc(sizeof(Stack));
  if (stack == NULL) {
    return NULL;
  }

  stack->data_size = data_size;
  stack->capacity = init_cap;
  stack->length = 0;
  stack->data = malloc(data_size * init_cap);
  if (stack->data == NULL) {
    free(stack);
    return NULL;
  }

  return stack;
}

void stack_free(Stack *stack) {
  if (stack == NULL) {
    return;
  }

  free(stack->data);
  free(stack);
}

size_t stack_length(const Stack *stack) {
  assert(stack != NULL);
  return stack->length;
}

int stack_push(Stack *stack, const void *val) {
  assert(stack != NULL);
  assert(val != NULL);

  if (stack->capacity <= stack->length) {
    size_t new_cap = stack->capacity * 2 + 1;
    void *new_data = realloc(stack->data, stack->data_size * new_cap);
    if (new_data == NULL) {
      return -1;
    }
    stack->capacity = new_cap;
    stack->data = new_data;
  }

  memcpy((char *)stack->data + (stack->length * stack->data_size), val,
         stack->data_size);
  stack->length++;
  return 0;
}

void stack_pop(Stack *stack, void *out) {
  assert(stack != NULL);
  assert(out != NULL);
  assert(stack->length > 0);
  stack->length--;
  memcpy(out, (char *)stack->data + (stack->length * stack->data_size),
         stack->data_size);
}

void stack_peek(const Stack *stack, void *out) {
  assert(stack != NULL);
  assert(out != NULL);
  assert(stack->length > 0);
  memcpy(out, (char *)stack->data + ((stack->length - 1) * stack->data_size),
         stack->data_size);
}
