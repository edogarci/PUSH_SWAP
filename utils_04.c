/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:11:23 by edogarci          #+#    #+#             */
/*   Updated: 2023/06/29 15:43:12 by edogarci         ###   ########.fr       */
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
	t_list *seg;

	seg = (*stack_head)->next;
	(*stack_head)->next = (*stack_head)->next->next;
	seg->next = *stack_head;
	*stack_head = seg;
	f_print_action(action);
}

//Get first and second minimum values
//positions in the stack
void	f_get_mins_pos(t_list *stack, int *f_min, int *s_min)
{
    int     index;
    t_list  *element;
    int     counter;

    *f_min = -1;
    *s_min = -1;
    index = 0;
    while (*f_min == -1 || *s_min == -1)
    {
        counter = 0;
        element = stack;
        while (element != NULL)
        {
            if (element->index == index)
            {
                if (*f_min == -1)
                {
                    *f_min = counter;
                    break;
                }
                else
                {
                    *s_min = counter;
                    break;
                }
            }
            element = element->next;
            counter++;
        }
        index++;
    }
}
/*void	f_get_mins_pos(t_list *stack, int *f_min, int *s_min)
{
    int		p;

    p = 0;
    while (stack != NULL)
    {
        if (stack->index == 0)
            *f_min = p;
        else if (stack->index == 1)
            *s_min = p;
        stack = stack->next;
        p++;
    }
}*/

//Performs a reverse rotate operation on given stack
void	f_do_rev_rot(t_list **stack, char *action)
{
	t_list	*last_element;
	t_list	*head_element;
    int cont;
    int len;

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
    last_element->next =  NULL;
	f_print_action(action);
}

//Sort a stack of three elements
void	f_sort_three_items(t_list **stack)
{
	int 	f_min;
	int		s_min;

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

//Push the lowest value in stack_from to stack_to.
void    f_push_lowest_value(t_list **stack_from, t_list **stack_to)
{
    int     pos;
    int     index;
    t_list  *item;
    char    found;

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
                break;
            }
            pos++;
            item = item->next;
        }
        index++;
    }
    if (pos == (f_get_stack_len(*stack_from) - 1))
        f_do_rev_rot(stack_from, "rra");
    else
    {
        while (pos-- > 0)
            f_do_rotate(stack_from, "ra");
    }
    f_do_push(stack_from, stack_to, "pb");
}
/*void    f_push_highest_value(t_list **stack_from, t_list **stack_to)
{
    int     pos;
    t_list  *item;

    pos = 0;
    item = *stack_from;
    while (item != NULL)
    {
        if (item->index == (f_get_stack_len(*stack_from) - 1))
            break;
        pos++;
        item = item->next;
    }
    while (pos-- > 0)
        f_do_rotate(stack_from, "ra");
    f_do_push(stack_from, stack_to, "pb");
}*/

//Sort a stack of four (4) elements.
//It pushes to STACK B, the higher value in the stack,
//then it uses the same algorithm used to sort three elements,
//and after that, push the element from STACK B to STACK A again
//and rotate the stack once to have the higher value as last item.
void    f_sort_four_items(t_list **stack_a, t_list **stack_b)
{
    f_push_lowest_value(stack_a, stack_b);
    f_sort_three_items(stack_a);
    f_do_push(stack_b, stack_a, "pa");
    //f_do_rotate(stack_a, "ra");
}

//Sort a stack of five (5) elements.
void    f_sort_five_items(t_list **stack_a, t_list **stack_b)
{
    f_push_lowest_value(stack_a, stack_b);
    f_sort_four_items(stack_a, stack_b);
    f_do_push(stack_b, stack_a, "pa");
    //f_do_rotate(stack_a, "ra");
}

//Simple sort for when given parameters are less than 6 numbers
//In this implementation, INSERTION algorithm has been used
void	f_sort_simple(t_list **stack_a, t_list **stack_b, int argc)
{
	if (f_is_sorted(*stack_a) != 0)
	{
		if (argc == 3)
			f_do_swap(stack_a, "sa");
		else if (argc == 4)
			f_sort_three_items(stack_a);
		else if (argc == 5)
            f_sort_four_items(stack_a, stack_b);
        else if (argc == 6)
            f_sort_five_items(stack_a, stack_b);
	}
}