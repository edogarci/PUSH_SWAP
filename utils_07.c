/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_07.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:25:38 by edogarci          #+#    #+#             */
/*   Updated: 2023/07/17 16:41:47 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Fill allocated memory with real argument value
void	f_assign_val(char *real, char *original, int start, int len)
{
	int		pos;

	pos = 0;
	while (start < f_get_str_len(original) && original[start] != ' '
		&& original[start] != '\0' && pos < len)
	{
		real[pos] = original[start];
		start++;
		pos++;
	}
	real[pos] = '\0';
}

//Iterates over arguments passed when calling the program.
//For each real argument (./push_swap "33 42" 55, are three real arguments)
//a MALLOC is done filling it with the real argument value
//No errors are checked at this point
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
			f_assign_val(arg_values[real_argc++], argv[cont], start, arg_len);
			start = start + arg_len;
		}
		cont++;
	}
}

//In case various numbers are provided as one argument
//(i.e ./push_swap "1 -3 -1", instead of ./push_swap 1 -3 1),
//this function split them in multiple arguments, updating original ARGC
char	**f_decompress_args(int *argc, char **argv, char **arg_values)
{
	int	real_argc;

	real_argc = f_count_real_args(argc, argv);
	arg_values = malloc((real_argc + 1) * sizeof(char *));
	if (arg_values)
	{
		arg_values[real_argc] = NULL;
		f_fill_arg_values(*argc, arg_values, argv);
		*argc = real_argc;
	}
	return (arg_values);
}
