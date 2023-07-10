/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:11:23 by edogarci          #+#    #+#             */
/*   Updated: 2023/07/07 11:41:07 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Returns a string length
int	f_get_str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

//Returns one (1) if both parameters are the same.
//To returns zero (0), at least one character
//has to be different
int	f_compare_params(char *str1, char *str2)
{
	int		i;
	int		len;

	len = f_get_str_len(str1);
	if (len <= f_get_str_len(str2))
		len = f_get_str_len(str2);
	i = 0;
	while (i < len)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

//Returns zero (0) if the stack is sorted
//It is used to stop a sorting algorithm if
//stack is already sorted
int	f_is_sorted(t_list *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->value <= stack->next->value)
			stack = stack->next;
		else
			return (1);
	}
	return (0);
}

//Swap two top items in a stack
//First becomes second, and second
//becomes first
void	f_do_swap(t_list **stack_head, char *action)
{
	t_list	*seg;

	seg = (*stack_head)->next;
	(*stack_head)->next = (*stack_head)->next->next;
	seg->next = *stack_head;
	*stack_head = seg;
	f_print_action(action);
}
