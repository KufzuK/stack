#ifndef STACK_H
#define STACK_H

struct Stack;
typedef struct Stack Stack;

typedef int elem_t;

Stack *stack_ctor (void);
void stack_dtor (Stack *stack);

#endif // STACK_H

