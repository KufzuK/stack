#include<stdlib.h>

#include "stack.h"

const int init_capacity = 10;

struct Stack
{
	elem_t *data;
	int size;
	int capacity;
};

Stack *stack_ctor (void)
{
	Stack *stack = (Stack *)calloc (1, sizeof (Stack));	
	if (stack == NULL)
		return NULL;

	stack->data = (elem_t *)calloc (init_capacity, sizeof (elem_t));
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

	change_size(stack);

	if (stack->size == stack->capacity)
	{
		double_capacity(stack);
	}

	stack->data[stack->size++] = value;
}

void stack_pop(Stack *stack)
{
	if (stack == NULL)
	   	return;	

	if (stack->size < stack->capacity / 4)
	{
		reduce_capacity(stack);
	}

	stack->data[stack->size--];

	return;
}

elem_t stack_top(Stack *stack)
{
	/*if (stack == NULL)
		return NULL;*/

	return stack->data[stack->size];
}

void double_capacity(Stack *stack)
{
	realloc(stack, 2 * stack->capacity * sizeof(elem_t));
	stack->capacity *= 2;
}

void reduce_capacity(Stack *stack)
{
	realloc(stack, stack->capacity / 2 * sizeof(elem_t));
	stack->capacity /= 2;
}
