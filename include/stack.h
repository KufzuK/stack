#ifndef STACK_H
#define STACK_H

#include "errors.h"
#include  <stdio.h>

struct Stack;
typedef struct Stack Stack;

typedef int elem_t;

#ifdef __cplusplus
extern "C"
{
#endif

typedef void (*print_elem) (FILE*, const elem_t);

Stack *stack_ctor (print_elem print);

void stack_dtor (Stack *stack);

void stack_push(Stack* stack, const elem_t value);

void stack_pop(Stack* stack);

elem_t stack_top(const Stack* stack);

void stack_dump(FILE* stream, const Stack* stack);

void example_of_dump_function(FILE* stream, const elem_t any_value);

int stack_capacity(const Stack* stack);

int stack_size(const Stack* stack);

#ifdef __cplusplus
}
#endif

#endif // STACK_H

