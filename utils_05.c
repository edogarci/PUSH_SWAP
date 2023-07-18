/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:20:25 by edogarci          #+#    #+#             */
/*   Updated: 2023/07/17 13:06:24 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Complementary function to f_push_lowest_value
//It should never be used alone.
//Only f_push_lowest_value should call it.
void	f_do_push_lowest(int pos, t_list **stack_from, t_list **stack_to)
{
	if (pos == (f_get_stack_len(*stack_from) - 1))
		f_do_rev_rot(stack_from, "rra");
	else
	{
		while (pos-- > 0)
			f_do_rotate(stack_from, "ra");
	}
	f_do_push(stack_from, stack_to, "pb");
}

//Push the lowest value in stack_from to stack_to.
void	f_push_lowest_value(t_list **stack_from, t_list **stack_to)
{
	int		pos;
	int		index;
	t_list	*item;
	char	found;

	found = ' ';
	index = 0;
	while (found == ' ')
	{
		item = *stack_from;
		pos = 0;
		while (item != NULL)
		{
			if (item->index == index)
			{
				found = 'X';
				break ;
			}
			pos++;
			item = item->next;
		}
		index++;
	}
	f_do_push_lowest(pos, stack_from, stack_to);
}

//Sort a stack of four (4) elements.
//It pushes to STACK B, the higher value in the stack,
//then it uses the same algorithm used to sort three elements,
//and after that, push the element from STACK B to STACK A again
//and rotate the stack once to have the higher value as last item.
void	f_sort_four_items(t_list **stack_a, t_list **stack_b)
{
	f_push_lowest_value(stack_a, stack_b);
	f_sort_three_items(stack_a);
	f_do_push(stack_b, stack_a, "pa");
}

//Sort a stack of five (5) elements.
void	f_sort_five_items(t_list **stack_a, t_list **stack_b)
{
	f_push_lowest_value(stack_a, stack_b);
	f_sort_four_items(stack_a, stack_b);
	f_do_push(stack_b, stack_a, "pa");
}

//Simple sort for when given parameters are less than 6 numbers
//In this implementation, INSERTION algorithm has been used
void	f_sort_simple(t_list **stack_a, t_list **stack_b, int argc)
{
	if (f_is_sorted(*stack_a) != 0)
	{
		if (argc == 2)
			f_do_swap(stack_a, "sa");
		else if (argc == 3)
			f_sort_three_items(stack_a);
		else if (argc == 4)
			f_sort_four_items(stack_a, stack_b);
		else if (argc == 5)
			f_sort_five_items(stack_a, stack_b);
	}
}
