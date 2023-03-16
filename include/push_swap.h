/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 18:41:31 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/16 22:57:40 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct s_stack
{
	int nb;
	struct s_stack	*next;
}	t_stack;

// main.c (tmp)
void print_split(char **s);


// stack_utils.c
t_stack *stack_dup(t_stack *head);
t_stack	*stack_min(t_stack *stack);
void 	stack_free(t_stack *head);
int 	stack_is_sorted(t_stack *head);


// stack.c
t_stack	*stack_new(int nb);
t_stack	*stack_last(t_stack *stack);
void 	stack_add_front(t_stack **stack, t_stack *new);
void 	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);


// operations.c
void 	operation_swap(t_stack **stack);
void 	operation_push(t_stack **src, t_stack **dst);
void 	operation_rotate(t_stack **stack);
void 	operation_reverse_rotate(t_stack **stack);


// utils.c
t_stack	*create_stack_a(char *args[], int len);
char	**strjoin_free_2d(char **s_base, char **s_append);
int		free_split(char **s_split);
int		str_arr_len(char **arr);


// parser.c
char	**parse_args(char *argv[]);


// moves.c
void sa(t_stack **stack_a);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **stack_a);
void rra(t_stack **stack_a);


// sort.c
int	do_sort(t_stack **head_a);


// radix.c 
int	sort_radix(t_stack **stack_a, t_stack **stack_b);


#endif
