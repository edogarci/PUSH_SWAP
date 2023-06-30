/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:10:12 by edogarci          #+#    #+#             */
/*   Updated: 2023/06/29 12:10:12 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Returns number of elements in a stack
int	f_get_stack_len(t_list *stack)
{
	int		stack_len;
	t_list	*element;

	element = stack;
	stack_len = 0;
	while (element->next != NULL)
	{
		stack_len++;
		element = element->next;
	}
	return (stack_len + 1);
}

//Returns 0 if any of the elements in stack
//does not have index value assigned
int	f_is_any_index_pending(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->index == -1)
			return (0);
		stack = stack->next;
	}
	if (stack->index == -1)
		return (0);
	else
		return (1);
}

//Iterate over stack elements (items),
//setting each index value
void	f_init_stack_indexes(t_list **stack_head)
{
	t_list	*min_item;
	t_list	*item;
	int		i;
	int		index;

	index = 0;
	min_item = NULL;
	item = *stack_head;
	while (f_is_any_index_pending(*stack_head) == 0)
	{
		i = 0;
		while (i++ < f_get_stack_len(*stack_head))
		{
			if ((min_item == NULL) && (item->index == -1))
					min_item = item;
			else if ((min_item != NULL)
				&& (item->value < min_item->value) && (item->index == -1))
					min_item = item;
			item = item->next;
		}
		min_item->index = index++;
		min_item = NULL;
		item = *stack_head;
	}
}

//Returns the maximum number of needed iterations
//to sort the stack. This number will be equal to
//the position of the last bit equal to one (1)
// of the largest number (counting right to left)
int	f_get_iterations_needed(t_list *stack)
{
	t_list	*element;
	int		needed_iter;
	int		iter;

	iter = 0;
	needed_iter = ((int) sizeof(int) * 8) - 1;
	element = stack;
	while (element != NULL)
	{
		needed_iter = (int) sizeof(int) * 8 - 1;
		//while ((((element->value >> needed_iter) & 1) == 0)
		while ((((element->index >> needed_iter) & 1) == 0)
			&& (needed_iter >= 0))
			needed_iter--;
		if (needed_iter > iter)
			iter = needed_iter;
		element = element->next;
	}
	return (iter + 1);
}

//Iterate over stack elements as many times as necessary,
//based on last N bit of the number, partly sorting the
//stack each of this iterations
void	f_sort_stack_elements(t_list **stack_a, t_list **stack_b)
{
	int	iteration_n;
	int	max_iter;

	iteration_n = 0;
	max_iter = f_get_iterations_needed(*stack_a);
	while (iteration_n < max_iter)
		f_sort_n_iteration(iteration_n++, stack_a, stack_b);
}
