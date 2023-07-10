/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_06.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:21:47 by edogarci          #+#    #+#             */
/*   Updated: 2023/07/10 16:27:14 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Get first and second minimum values
//positions in the stack
void	f_get_mins_pos(t_list *stack, int *f_min, int *s_min)
{
	int		index;
	int		counter;
	t_list	*stack_head;

	index = 0;
	stack_head = stack;
	while (*f_min == -1 || *s_min == -1)
	{
		counter = 0;
		stack = stack_head;
		while (stack != NULL)
		{
			if ((stack->index == index) && (*f_min == -1))
				*f_min = counter;
			else if ((stack->index == index) && (*f_min != -1))
				*s_min = counter;
			stack = stack->next;
			counter++;
		}
		index++;
	}
}

//Performs a reverse rotate operation on given stack
void	f_do_rev_rot(t_list **stack, char *action)
{
	t_list	*last_element;
	t_list	*head_element;
	int		cont;
	int		len;

	cont = 0;
	len = f_get_stack_len(*stack);
	head_element = (*stack)->next;
	last_element = *stack;
	while (last_element->next != NULL)
		last_element = last_element->next;
	last_element->next = *stack;
	*stack = last_element;
	while (cont++ < (len - 1))
		last_element = last_element->next;
	last_element->next = NULL;
	f_print_action(action);
}

//Sort a stack of three elements
void	f_sort_three_items(t_list **stack)
{
	int	f_min;
	int	s_min;

	f_min = -1;
	s_min = -1;
	f_get_mins_pos(*stack, &f_min, &s_min);
	if (f_min == 0 && s_min == 2)
	{
		f_do_rotate(stack, "ra");
		f_do_swap(stack, "sa");
		f_do_rev_rot(stack, "rra");
	}
	else if (f_min == 1 && s_min == 0)
		f_do_swap(stack, "sa");
	else if (f_min == 2 && s_min == 0)
		f_do_rev_rot(stack, "rra");
	else if (f_min == 1 && s_min == 2)
		f_do_rotate(stack, "ra");
	else if (f_min == 2 && s_min == 1)
	{
		f_do_rotate(stack, "ra");
		f_do_swap(stack, "sa");
	}
}

//Returns real amount of arguments passed to progam
//and allocate a char pointer to N char pointers (as many as real arguments)
int	f_count_args(int argc, char **argv, char **arg_values)
{
	int		cont;
	int		real_amount;
	int		start;

	real_amount = 0;
	cont = 1;
	while (cont < argc)
	{
		start = 0;
		while (start <= f_get_str_len(argv[cont]))
		{
			if (argv[cont][start] == ' ' || argv[cont][start] == '\0')
				real_amount++;
			start++;
		}
		cont++;
	}
	arg_values = malloc((real_amount + 1) * sizeof(char *));
	if (!arg_values)
		return (-1);
	return (real_amount);
}

void	f_asigna_valor(char **values, int curval, char *str, int len)
{
	int	p;

	p = 0;
	while (p < len)
	{
		values[curval][p] = str[p];
		p++;
	}
}

//Create one 'argument', one for each number passed to the program
//(i.e) ./push_swap "1111" 4 "1 3a" will be:
// - arg_values[0] = 1111
// - arg_values[1] = 4
// - arg_values[2] = 1
// - arg_values[3] = 3a
//---Errors will be handled in f_check_params and f_atoi---
void	f_create_real_args(int *arg_n, char **values, int argc, char **argv)
{
	int	curr_argv;
	int	i;
	int	start;
	int	curval;

	curval = 0;
	start = -1;
	curr_argv = 0;
	i = 0;
	while (curr_argv < argc)
	{
		while (i <= f_get_str_len(argv[curr_argv]))
		{
			if ((argv[curr_argv][i] != ' ') && (argv[curr_argv][i] != '\0') && (start == -1))
				start = i;
			if ((argv[curr_argv][i] == ' ') || (argv[curr_argv][i] == '\0'))
			{
				values[curval] = malloc((i - start + 1) * sizeof(char));
				f_asigna_valor(values, curval, &(argv[curr_argv][start]), i);
			}
			i++;
		}
		curr_argv++;
	}
}

//In case various numbers are provided as one argument
//(i.e ./push_swap "1 -3 -1", instead of ./push_swap 1 -3 1),
//this function split them in multiple arguments
void	f_decompress_args(int argc, char **argv, int *arg_n, char **arg_values)
{
	*arg_n = f_count_args(argc, argv, arg_values);
	if (*arg_n != -1)
		f_create_real_args(arg_n, arg_values, argc, argv);
}
