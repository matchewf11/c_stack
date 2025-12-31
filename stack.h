#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct stack Stack;

// Create a new stack.
//
// @param init_cap Initial Capacity of the stack
// @param data_size Size in bytes of each element to store
// @return Pointer to new stack or NULL if it fails
//
// @note call stack_free when done with memory
Stack *stack_build(size_t init_cap, size_t data_size);

// Free a allocated stack.
//
// @param stack Stack to free
void stack_free(Stack *stack);

// Returns length of stack.
//
// @param stack Stack that you want length of
//
// @note make sure stack is not null
size_t stack_length(const Stack *stack);

// Push an element onto a stack.
//
// @param stack Stack that you want to push element onto
// @param val Pointer to the element you want to copy over
// @return 0 if success | -1 if failed to realloc
//
// @note make sure both are not NULL
int stack_push(Stack *stack, const void *val);

// Pop an element off a stack.
//
// @param stack Stack that you want to pop off of
// @param out Out param that we will write value to
//
// @note make sure stack and out are not null and stack is not empty
void stack_pop(Stack *stack, void *out);

// Peek an element off a stack.
//
// @param stack Stack that you want to peek off of
// @param out Out param that we will write value to
//
// @note make sure stack and out are not null and stack is not empty
void stack_peek(const Stack *stack, void *out);

// Macro to auto-generate type wrapper for a stack
// stack_length and stack_free are not needed
#define DEFINE_STACK_TYPE_WRAPPER(TYPE)                                        \
  typedef Stack StackInt;                                                      \
  static inline StackInt *stack_build_##TYPE(size_t init_cap) {                \
    return stack_build(init_cap, sizeof(TYPE));                                \
  }                                                                            \
  static inline TYPE stack_push_##TYPE(StackInt *stack, TYPE val) {            \
    return stack_push(stack, &val);                                            \
  }                                                                            \
  static inline TYPE stack_pop_##TYPE(StackInt *stack) {                       \
    TYPE out;                                                                  \
    stack_pop(stack, &out);                                                    \
    return out;                                                                \
  }                                                                            \
  static inline TYPE stack_peek_##TYPE(StackInt *stack) {                      \
    TYPE out;                                                                  \
    stack_peek(stack, &out);                                                   \
    return out;                                                                \
  }

#endif
