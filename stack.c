#include<stdlib.h>

#include "stack.h"

const int init_capacity = 10;

struct Stack
{
	elem_t *data;
	int size;
	int capacity;
};

Stack *stack_ctor (/*error_t* error*/)
{
	/*if (error == NULL)
		return NULL;*/
	
	Stack *stack = (Stack *)calloc (1, sizeof (Stack));	
	if (stack == NULL)
	{
		//*error = null_ptr_arg;
		return NULL;
	}

	stack->data = (elem_t *)calloc (init_capacity, sizeof (elem_t));
	if (stack->data == NULL)
	{
		//*error = null_ptr;
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

	if (stack->size == stack->capacity)
	{
		double_capacity(stack); // too big capacity
	}

	stack->data[stack->size++] = value;
}

void stack_pop(Stack *stack)
{
	if (stack == NULL)
	   	return;	
	if (stack->data == NULL)
		return;

	if (stack->size < stack->capacity / 4)
	{
		reduce_capacity(stack); // zero capacity
	}

	stack->data[stack->size--];

	return;
}

elem_t stack_top(Stack *stack)
{
	if (stack == NULL)
		return 1; 

	if (stack->data == NULL)
		return 2;

	return stack->data[stack->size];
}

void double_capacity(Stack *stack)
{
	if (stack == NULL)
		return;

	/*if (stack->capacity >= MAX_MEMORY_ALLOWED / 2)
		return;*/
	
	realloc(stack, 2 * stack->capacity * sizeof(elem_t));
	stack->capacity *= 2;

	if (stack == NULL)
		return;
}

void reduce_capacity(Stack *stack)
{
	if (stack == NULL)
		return;
	
	realloc(stack, stack->capacity / 2 * sizeof(elem_t));
	stack->capacity /= 2;

	if (stack == NULL)
		return;

	if (stack->capacity <= 0)
		return;
	
}
