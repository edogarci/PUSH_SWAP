/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:10:25 by edogarci          #+#    #+#             */
/*   Updated: 2023/07/17 14:36:50 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//This program sorts a given list of integers using two stacks
//(using linked lists in this implementation) and RADIX algorithm
int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**arg_values;

	stack_a = NULL;
	stack_b = NULL;
	arg_values = f_decompress_args(&argc, argv, arg_values = NULL);
	if (argc >= 1)
	{
		if (f_check_params(argc, arg_values) != 0)
			return (f_mem(&stack_a, arg_values), write(2, "Error\n", 6), 1);
		if (f_init_stack(argc, arg_values, &stack_a) != 0)
			return (f_mem(&stack_a, arg_values), write(2, "Error\n", 6), 1);
		f_init_stack_indexes(&stack_a);
		if (argc < 6)
			f_sort_simple(&stack_a, &stack_b, argc);
		else
			f_sort_radix(&stack_a, &stack_b);
	}
	f_mem(&stack_a, arg_values);
	return (0);
}
