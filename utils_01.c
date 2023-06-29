//
// Created by Edo on 26/06/2023.
//

#include "push_swap.h"

//Converts params from char * type to integer type
static int f_atoi(const char *str)
{
	long n;
	int dec;
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	n = 0;
	dec = 1;
	while ((len - 1) >= 0)
	{
		if ((len == 0) && (str[len] == '-'))
			n = n * -1;
		else
		{
			n = n + ((str[len - 1] - '0') * dec);
			dec = dec * 10;
		}
		len--;
	}
	return ((int)n);
}

//Initialize STACK with given parameters.
//First parameter is the one on top. After it converts
//param to proper integer, it is assigned to stack a,
//as an element of the linked list representing the stack
void	f_init_stack(int argc, char **argv, t_list **stack_head)
{
	int num;
	int cont;
	t_list *stack_element;

	stack_element = NULL;
	cont = 1;
	num = 0;
	while(cont < argc)
	{
		num = f_atoi(argv[cont]);
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
		stack_element->value = num;
		stack_element->index = -1;
		stack_element->next = NULL;
		cont++;
	}
}

//Check if all parameters given when calling program
//are proper integers
static int f_check_integers(int argc, char **argv)
{
	int cont;
	int p;
	char *s;

	cont = 1;
	while (cont < argc)
	{
		s = argv[cont];
		p = 0;
		while (s[p] != '\0')
		{
			if ((p == 0) && (s[p] != '-' && !(s[p] >= '0' && s[p] <= '9')))
					return (1);
			else if ((p != 0) && !(s[p] >= '0' && s[p] <= '9'))
					return(1);
			p++;
		}
		cont++;
	}
	return (0);
}

//Compares all parameters to check if any duplicate exists
/*static int f_check_duplicates(int argc, char **argv)
{
	int cont;
	int n;

	cont = 1;
	while (*(argv[cont]) != '\0')
	{
		n = 1;
		while (*(argv[cont + n]) != '\0')
		{
			if (*(argv[cont]) == *(argv[cont + n]))
				return (1);
			n++;
		}
		cont++;
	}
	return (0);
}*/

int f_check_params(int argc, char **argv)
{
	if (f_check_integers(argc, argv) != 0)
		return (1);
/*	else if (f_check_duplicates(argc, argv) != 0)
		return (1);*/
	return (0);
}