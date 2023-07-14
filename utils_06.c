/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_06.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:21:47 by edogarci          #+#    #+#             */
/*   Updated: 2023/07/14 15:16:33 by edogarci         ###   ########.fr       */
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

//Counts real amount of arguments when they are passed
//in between " ", ie. "-1 3 0 42", returns 4
int	f_count_real_args(int *argc, char **argv)
{
	int		real_args;
	int		cont;
	int		pos;
	char	*s;

	real_args = 0;
	cont = 1;
	while (cont < *argc)
	{
		s = argv[cont];
		pos = 0;
		while (pos <= f_get_str_len(s) && s[pos] == ' ')
			pos++;
		while (pos <= f_get_str_len(s))
		{
			if (pos == 0 && s[pos] != ' ')
				real_args++;
			if (s[pos - 1] == ' ' && (s[pos] != ' ' && s[pos] != '\0'))
				real_args++;
			pos++;
		}
		cont++;
	}
	return (real_args);
}

int	f_get_next_arg_len(int start, char *str)
{
	int	len;

	len = 0;
	while (start < f_get_str_len(str) && str[start] != ' ' && str[start] != '\0')
	{
		start++;
		len++;
	}
	return (len);
}

void	f_fill_arg_values(int argc, char **arg_values, char **argv)
{
	int		start;
	int		arg_len;
	int		cont;
	int		real_argc;

	real_argc = 0;
	cont = 1;
	while (cont < argc)
	{
		start = 0;
		while (start < f_get_str_len(argv[cont]))
		{
			if (argv[cont][start] == '\0')
				break ;
			while (argv[cont][start] == ' ')
				start++;
			arg_len = f_get_next_arg_len(start, argv[cont]);
			if (arg_len == 0)
				break ;
			arg_values[real_argc] = malloc((arg_len + 1) * sizeof(char));
			//asigna valor parametro
			real_argc++;
			start = start + arg_len;
		}
		cont++;
	}
}

//In case various numbers are provided as one argument
//(i.e ./push_swap "1 -3 -1", instead of ./push_swap 1 -3 1),
//this function split them in multiple arguments, updating original ARGC
void	f_decompress_args(int *argc, char **argv, char **arg_values)
{
	int	real_argc;

	real_argc = f_count_real_args(argc, argv);
	arg_values = malloc((real_argc + 1) * sizeof(char *));
	arg_values[real_argc] = NULL;
	f_fill_arg_values(*argc, arg_values, argv);
	*argc = real_argc;
}
