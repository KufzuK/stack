#include <gtest/gtest.h>
#include "stack.h"

TEST (standard_cases, size_1)
{
	Stack* stack = stack_ctor(NULL);
	stack_push(stack, 5);
	EXPECT_TRUE (stack_top(stack) == 5);
	stack_dtor(stack);
}

TEST (standard_cases, size2)
{
	Stack* stack = stack_ctor(NULL);
	stack_push(stack,   4);
	stack_push(stack, -18);
	
	EXPECT_TRUE (stack_top(stack) == -18);
	stack_dtor(stack);
}

TEST (standard_cases, using_pop)
{
	Stack* stack = stack_ctor(NULL);
	stack_push(stack,   44);
	stack_push(stack, -918);
	EXPECT_TRUE(stack_top(stack) == -918);
	EXPECT_TRUE(stack_size(stack) == 2);
	stack_pop (stack);
	
	EXPECT_TRUE(stack_capacity(stack) == 10);
	EXPECT_TRUE(stack_size(stack) == 1);
	
	EXPECT_TRUE (stack_top(stack) == 44);
	stack_dtor(stack);
}


TEST (standard_cases, using_pop_2)
{
	Stack* stack = stack_ctor(NULL);
	stack_push(stack,  -83);
	stack_push(stack, -918);
	stack_push(stack,  245);
	stack_pop (stack);
	stack_pop (stack);
	
	EXPECT_TRUE (stack_top(stack) == -83);
	stack_dtor(stack);
}


#if(0)
TEST (standard_cases, using_pop3)
{
	Stack* stack = stack_ctor(NULL);
	stack_push(stack,   67);
	stack_push(stack,  111);
	stack_pop (stack);
	stack_pop (stack);
	stack_pop (stack);
	EXPECT_TRUE (error_t == );
	stack_dtor(stack);
}
#endif

#if(0)
TEST (standard_cases, using_top)
{
	Stack* stack = stack_ctor(NULL);
	stack_push(stack, -4);
	stack_push(stack, 18);
	stack_pop (stack);
	stack_pop (stack);
	
	elem_t result = stack_top(stack);
	
	
	EXPECT_TRUE (error_t ==)stack_dtor(stack);
	stack_dtor(stack);
}
#endif	

TEST (memory_checking, increase1)
{
	Stack* stack = stack_ctor(NULL);
	
	for (size_t i = 0; i < 12; i++)
	{
		stack_push(stack, 4);
	}
	
	EXPECT_TRUE(stack_capacity(stack) == 20);
	stack_dtor(stack);

}


TEST (memory_checking, increase2)
{
	Stack* stack = stack_ctor(NULL);
	
	for (size_t i = 0; i < 22; i++)
	{
		stack_push(stack, 11);
	}


	EXPECT_TRUE(stack_capacity(stack) == 40);

	stack_dtor(stack);
						
}

TEST (memory_checking, reduce)
{
	Stack* stack = stack_ctor(NULL);
	
	for (size_t i = 0; i < 11; i++)
	{
		stack_push(stack, 4);
	}
	
	EXPECT_TRUE(stack_capacity(stack) == 20);

	for (size_t i = 0; i < 7; i++)	
	{
		stack_pop(stack);
	}
	EXPECT_TRUE(stack_capacity(stack) == 10);

	stack_pop  (stack);
	stack_pop  (stack);
	stack_pop  (stack);
	
	EXPECT_TRUE(stack_capacity(stack) == 10);
	stack_dtor(stack);
}

TEST (memory_checking, increase3)
{
	Stack* stack = stack_ctor(NULL);
	
	for (size_t i = 0; i < 12; i++)
	{
		stack_push(stack, 4);
	}
	
	EXPECT_TRUE(stack_capacity(stack) == 20);
	stack_dtor(stack);
}	
