/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:10:03 by edogarci          #+#    #+#             */
/*   Updated: 2023/06/29 12:10:03 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Converts params from char * type to integer type
int	f_atoi(const char *str, int *numero)
{
	long long	num;
	long long	dec;
	int			len;

	len = 0;
	while (str[len] != '\0')
		len++;
	num = 0;
	dec = 1;
	while ((len - 1) >= 0)
	{
		if (((len - 1) == 0) && (str[len - 1] == '-'))
			num = num * -1;
		else
		{
			num = num + ((str[len - 1] - '0') * dec);
			dec = dec * 10;
		}
		len--;
	}
	if (num < -2147483648 || num > 2147483647)
		return (1);
	*numero = (int)num;
	return (0);
}

//Initialize STACK with given parameters.
//First parameter is the one on top. After it converts
//param to proper integer, it is assigned to stack a,
//as an element of the linked list representing the stack
int	f_init_stack(int argc, char **argv, t_list **stack_head)
{
	int		cont;
	t_list	*stack_element;

	stack_element = NULL;
	cont = 0;
	while (cont < argc)
	{
		if (!stack_element)
		{
			stack_element = malloc(sizeof(t_list));
			if (stack_element)
				*stack_head = stack_element;
		}
		else
		{
			stack_element->next = malloc(sizeof(t_list));
			if (stack_element->next)
				stack_element = stack_element->next;
		}
		if (f_atoi(argv[cont++], &(stack_element->value)) != 0)
			return (1);
		stack_element->index = -1;
		stack_element->next = NULL;
	}
	return (0);
}

//Check if all parameters given when calling program
//are proper integers
int	f_check_integers(int argc, char **argv)
{
	int		cont;
	int		p;
	char	*s;

	cont = 0;
	while (cont < argc)
	{
		s = argv[cont];
		if ((s[1] == '\0') && !(s[0] >= '0' && s[0] <= '9'))
			return (1);
		p = 0;
		while (s[p] != '\0')
		{
			if ((p == 0) && (s[p] != '-' && !(s[p] >= '0' && s[p] <= '9')))
				return (1);
			else if ((p != 0) && !(s[p] >= '0' && s[p] <= '9'))
				return (1);
			p++;
		}
		cont++;
	}
	return (0);
}

//Compares all parameters to check if there are duplicates
int	f_check_duplicates(int argc, char **argv)
{
	int	j;
	int	i;
	int	n1;
	int	n2;

	j = 0;
	while (j < argc)
	{
		i = 0;
		while (i < argc)
		{
			if (j != i)
			{
				if (f_compare_params(argv[j], argv[i]) != 0)
					return (1);
				if ((f_atoi(argv[j], &n1) != 0) || (f_atoi(argv[i], &n2) != 0)
					|| (n1 == n2))
					return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

//Check if parameters are correct:
// - No duplicates
// - No float numbers
// - No numbers larger than integer type can handle (checked in F_ATOI)
int	f_check_params(int argc, char **argv)
{
	if (f_check_integers(argc, argv) != 0)
		return (1);
	if (f_check_duplicates(argc, argv) != 0)
		return (1);
	return (0);
}
