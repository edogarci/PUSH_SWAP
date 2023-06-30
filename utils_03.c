/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:10:17 by edogarci          #+#    #+#             */
/*   Updated: 2023/06/29 12:10:17 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Free allocated memory
void	f_clear_mem(t_list **stack)
{
	t_list	*head;

	while (*stack != NULL)
	{
		head = (*stack)->next;
		free(*stack);
		*stack = head;
	}
}

//Print on screen executed action (pa, pb, ra...)
void	f_print_action(const char *action)
{
	int		len;
	char	nl;
	char	c;

	nl = '\n';
	len = 0;
	while (action[len] != '\0')
	{
		c = action[len];
		write(1, &c, 1);
		len++;
	}
	write(1, &nl, 1);
}

//Top item on stack becomes last, so second becomes first
void	f_do_rotate(t_list **stack, const char *action)
{
	t_list	*aux;

	aux = *stack;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = *stack;
	aux = (*stack)->next;
	(*stack)->next = NULL;
	*stack = aux;
	f_print_action(action);
}

//Move top item on "STACK FROM" to top of "STACK TO"
void	f_do_push(t_list **stack_from, t_list **stack_to, const char *action)
{
	t_list	*aux;
	t_list	*head_from;
	t_list	*head_to;

	if (*stack_from != NULL)
	{
		head_to = *stack_to;
		head_from = *stack_from;
		aux = head_from;
		head_from = head_from->next;
		*stack_from = head_from;
		if (head_to == NULL)
		{
			head_to = aux;
			head_to->next = NULL;
			*stack_to = head_to;
		}
		else
		{
			aux->next = head_to;
			*stack_to = aux;
		}
	}
	f_print_action(action);
}

void	f_sort_n_iteration(int iteration, t_list **stack_a, t_list **stack_b)
{
	int	len;
	int	n;

	n = 0;
	len = f_get_stack_len(*stack_a);
	while (n++ < len)
	{
		//if ((((*stack_a)->value >> iteration) & 1) == 0)
		if ((((*stack_a)->index >> iteration) & 1) == 0)
			f_do_push(stack_a, stack_b, "pb");
		else
			f_do_rotate(stack_a, "ra");
	}
	while (*stack_b != NULL)
		f_do_push(stack_b, stack_a, "pa");
}
