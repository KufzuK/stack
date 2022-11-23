#ifndef STACK_H
#define STACK_H

#include "errors.h"

struct Stack;
typedef struct Stack Stack;

typedef int elem_t;

Stack *stack_ctor (void);
void stack_dtor (Stack *stack);

/*int MAX_MEMORY_ALLOWED = 10000;*/

#endif // STACK_H

