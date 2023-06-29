#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
} t_list;

int		f_check_params(int argc, char **argv);
void	f_init_stack(int argc, char **argv, t_list **stack);
void	f_init_stack_indexes(t_list **stack);
void	f_sort_stack_elements(t_list **stack_a, t_list **stack_b);
void	f_sort_n_iteration(int iteration, t_list **stack_a, t_list **stack_b);
void	f_do_push(t_list **stack_from, t_list **stack_to, const char *action);
int		f_get_stack_len(t_list *stack);
int		f_get_iterations_needed(t_list *stack);
void	f_clear_mem(t_list **stack);

#endif
