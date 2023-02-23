/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 18:41:31 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/23 16:31:32 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include "libft.h"

typedef struct s_stack
{
	int nb;
	struct s_stack	*next;
}	t_stack;


// stack.c
t_stack *stack_dup(t_stack *head);
int 	stack_is_sorted(t_stack *head);
void 	stack_free(t_stack *head);
void 	stack_add_front(t_stack **stack, t_stack *new);
void 	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_new(int nb);


// operations.c
void 	operation_swap(t_stack **stack);
void 	operation_push(t_stack **src, t_stack **dst);
void 	operation_rotate(t_stack **stack);
void 	operation_reverse_rotate(t_stack **stack);


// utils.c
void 	print_stacks(t_stack *head_a, t_stack *head_b);
long 	ft_atol(const char *s);
char 	*bin_to_str(int bin);


// parser.c
int parse_args(char *argv[]);


// moves.c
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b);

void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);

void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);

void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);


// radix.c
void 	radixsort(t_stack **stack_a, t_stack **stack_b);


#endif
