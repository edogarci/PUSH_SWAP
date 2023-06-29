#include "push_swap.h"
#include <stdio.h>

//This program sorts a given list of integers using two stacks
//(using linked lists in this implementation) and RADIX algorithm
int	main(int argc, char *argv[])
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (f_check_params(argc, argv) != 0)
			return (write(1, "Error", 5), 1);
		f_init_stack(argc, argv, &stack_a);
		f_init_stack_indexes(&stack_a);
		f_sort_stack_elements(&stack_a, &stack_b);
	}
	///BORRAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	t_list *DELETE = stack_a;
	while (stack_a != NULL)
	{
		printf("%i, ", stack_a->value);
		stack_a = stack_a->next;
	}
	stack_a = DELETE;
	///BORRAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	f_clear_mem(&stack_a);
	//f_clear_mem(&stack_b);
	return (0);
}