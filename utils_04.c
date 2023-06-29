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
