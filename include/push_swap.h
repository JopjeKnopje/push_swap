/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 18:41:31 by joppe         #+#    #+#                 */
/*   Updated: 2023/04/12 22:58:48 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}	t_stack;

// stack_utils.c
t_stack	*stack_dup(t_stack *head);
t_stack	*stack_min(t_stack *stack);
void	stack_free(t_stack *head);
int		stack_is_sorted(t_stack *head);

// stack.c
t_stack	*stack_new(int nb);
t_stack	*stack_last(t_stack *stack);
t_stack *stack_add_front(t_stack **stack, t_stack *new);
t_stack *stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);

// operations.c
t_stack	*operation_swap(t_stack **stack);
t_stack *operation_push(t_stack **src, t_stack **dst);
t_stack	*operation_rotate(t_stack **stack);
t_stack *operation_reverse_rotate(t_stack **stack);

// utils.c
t_stack	*create_stack_a(char *args[], int len);
char	**strjoin_free_2d(char **s_base, char **s_append);
int		free_split(char **s_split);
int		str_arr_len(char **arr);

// parser.c
char	**parse_args(char *argv[]);

// moves.c
int		sa(t_stack **stack_a);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		ra(t_stack **stack_a);
int		rra(t_stack **stack_a);

// sort.c
int		do_sort(t_stack **head_a);

// radix.c 
int		sort_radix(t_stack **stack_a, t_stack **stack_b);

#endif
