#include "stack.h"

int main (void)
{
	Stack *stack = stack_ctor (NULL);
	
	stack_push(stack, 6);
	int a = stack_top(stack);

	printf("%d", a);

	stack_dtor (stack);
	
	return 0;
}

