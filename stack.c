#include <stdlib.h>

#include "stack.h"

const int init_capacity = 10;

struct Stack
{
	data_t *data;
	int size;
	int capacity;
};

Stack *stack_ctor (void)
{
	Stack *stack = (Stack *)calloc (1, sizeof (Stack));	
	if (stack == NULL)
		return NULL;

	stack->data_ = (elem_t *)calloc (init_capacity, sizeof (elem_t));
	if (stack->data == NULL)
	{
		free (stack);
		return NULL;
	}

	stack->capacity = init_capacity;

	return stack;
}

void stack_dtor (Stack *stack)
{
	if (stack == NULL)
		return;

	free (stack->data);
	free (stack);
}


void stack_push(Stack *stack, const elem_t value)

{	
	if (stack == NULL)
		return;

	if (stack->data == NULL)
		return;

	stack->data[stack->size++] = value;
}

/*stack_pop(Stack *stack)
{
	
}*/
