#include "stack.h"

int main (void)
{
	Stack *stack = stack_ctor ();
	stack_dtor (stack);

	return 0;
}

