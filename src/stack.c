#include <stdlib.h>
#include  <stdio.h>
#include  "stack.h"

const int                  init_capacity = 10;
const int           capacity_change_coef =  2;
const int capacity_condition_for_realloc =  4;

//stactic functions

struct Stack
{
	elem_t *data;
	int size;
	int capacity;
	print_elem elem_dump;
};

Stack *stack_ctor (print_elem print /* error_t* error*/)
{
	/*if (error == NULL)
	{
	#ifdef err_info
	err_t err = null_ptr;
	#endif
	
		return NULL;
	}
	*/
	
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
	
	stack->elem_dump = print;

	stack->capacity = init_capacity;
	stack->size = 0;

	return stack;
}

void stack_dtor (Stack *stack)
{
	if (stack == NULL)
		return;

	free (stack->data);
	free (stack);
}

static void increase_capacity(Stack* stack);
static void   reduce_capacity(Stack* stack);

void stack_push(Stack *stack, const elem_t value)
{	
	if (stack == NULL)
		return;

	if (stack->data == NULL)
		return;

	if (stack->size == stack->capacity)
	{
		int old_capacity = stack->capacity;
		increase_capacity(stack);		

		if (old_capacity == stack->capacity)
			return; // error
	}

	stack->data[stack->size++] = value;
}

void stack_pop(Stack *stack)
{
	if (stack == NULL || stack->data == NULL)
	   	return;

	if (stack->size == 0)  /*minimum size*/
		return;

	if (stack->size <= stack->capacity / capacity_condition_for_realloc && stack->capacity > init_capacity) //coef
	{
		int old_capacity = stack->capacity;
		reduce_capacity(stack); // zero capacity until init capacity
		
		if (old_capacity == stack->capacity)
			return; //error
		
	}
	stack->data[--stack->size] = 0;

	return;
}

elem_t stack_top(const Stack *stack)
{
	if (stack == NULL)
		return 0; 

	if (stack->data == NULL)
		return 0;
	
	if (stack->size == 0)
		return 0;           /*no elements yet*/

	return stack->data[stack->size - 1];
}

static void increase_capacity(Stack *stack)
{
	if (stack == NULL)
		return;
	
	stack->capacity *= capacity_change_coef;
	elem_t* new_data_ptr = (elem_t*) realloc(stack->data, stack->capacity * sizeof(elem_t));
	
	if (new_data_ptr == NULL)
	{
		stack->capacity /= capacity_change_coef;
		return;
	}

	stack->data = new_data_ptr;		
}

static void reduce_capacity(Stack *stack)
{
	if (stack == NULL)
		return;
	#if(0)
	if (stack->capacity / capacity_change_coef < init_capacity) // seems to be no neccessity in error_t here
		return;
	#endif

	stack->capacity /= capacity_change_coef; 
	elem_t* new_data_ptr = (elem_t*) realloc(stack->data, stack->capacity * sizeof(elem_t));	
		
	if (new_data_ptr == NULL)
	{
		stack->capacity *= capacity_change_coef; 
		return;
	}
		
	stack->data = new_data_ptr;
}

void stack_dump(FILE* stream, const Stack* stack)
{
	if (stack == NULL)  // stack == null in fprintf or here??
		return;
	
	fprintf(stream, "Current size of stack is %d."
					"\nCurrent capacity of stack is %d. \n", stack->size, stack->capacity);
	
	if (stack->elem_dump == NULL)
	{
		fprintf(stream, "The pointer to function giving extra information about the elements is NULL");
		return;
	}
	fprintf(stream, "The top element of stack is");
	stack->elem_dump(stream, stack->data[stack->size - 1]);		
	putc('\n', stream);
}
	
void example_of_dump_function(FILE* stream, const elem_t any_value)
{
	fprintf(stream, "%d", any_value);
}

int stack_capacity(const Stack* stack)
{
	return stack->capacity;
}

int stack_size(const Stack* stack)
{
	return stack->size;	
}
