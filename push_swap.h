/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:10:22 by edogarci          #+#    #+#             */
/*   Updated: 2023/06/29 12:10:22 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <stddef.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

char	**f_decompress_args(int *argc, char **argv, char **arg_values);
void	f_init_stack_indexes(t_list **stack_head);
void	f_sort_simple(t_list **stack_a, t_list **stack_b, int argc);
void	f_sort_radix(t_list **stack_a, t_list **stack_b);
void	f_mem(t_list **stack, char **args);
void	f_print_action(const char *action);
void	f_do_rotate(t_list **stack, const char *action);
void	f_do_push(t_list **stack_from, t_list **stack_to, const char *action);
void	f_sort_n_iteration(int iteration, t_list **stack_a, t_list **stack_b);
void	f_do_swap(t_list **stack_head, char *action);
void	f_sort_three_items(t_list **stack);
void	f_sort_four_items(t_list **stack_a, t_list **stack_b);
void	f_sort_five_items(t_list **stack_a, t_list **stack_b);
void	f_do_rev_rot(t_list **stack, char *action);
void	f_push_lowest_value(t_list **stack_from, t_list **stack_to);
void	f_assign_val(char *real, char *original, int start, int len);
void	f_fill_arg_values(int argc, char **arg_values, char **argv);
int		f_init_stack(int argc, char **argv, t_list **stack_head);
int		f_check_duplicates(int argc, char **argv);
int		f_get_iterations_needed(t_list *stack);
int		f_check_integers(int argc, char **argv);
int		f_check_params(int argc, char **argv);
int		f_get_stack_len(t_list *stack);
int		f_get_str_len(char *str);
int		f_is_any_index_pending(t_list *stack);
int		f_atoi(const char *str, int *numero);
int		f_compare_params(char *str1, char *str2);
int		f_is_sorted(t_list *stack);
int		f_get_next_arg_len(int start, char *str);
int		f_count_real_args(int *argc, char **argv);

#endif