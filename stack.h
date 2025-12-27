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

#endif
