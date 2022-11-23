#ifndef ERRORS_H
#define ERRORS_H

typedef enum 
{
	success,
	memory_error,
	null_ptr,
	null_ptr_arg,
	stack_size_zero,
	max_memory_used
} error_t;

#endif // ERRORS_H

