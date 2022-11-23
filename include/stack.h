#ifndef STACK_H
#define STACK_H

#include "errors.h"
#include  <stdio.h>

struct Stack;
typedef struct Stack Stack;

typedef int elem_t;

typedef void (*print_elem) (FILE*, const elem_t);

Stack *stack_ctor (print_elem print);

void stack_dtor (Stack *stack);

void stack_push(Stack* stack, const elem_t value);

void stack_pop(Stack* stack);

elem_t stack_top(const Stack* stack);

void stack_dump(FILE* stream, const Stack* stack);



/*int MAX_MEMORY_ALLOWED = 10000;*/

#endif // STACK_H

