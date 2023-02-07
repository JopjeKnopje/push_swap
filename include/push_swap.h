/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 18:41:31 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/07 09:37:45 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include "libft.h"

typedef struct s_stack
{
	int 			nb;
	struct s_stack	*next;
}	t_stack;


// stack.c
void 	stack_free(t_stack **head);
void 	stack_add_front(t_stack **stack, t_stack *new);
void 	stack_free(t_stack **head);
void 	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
t_stack	*stack_new(int nb);


// operations.c
void 	operation_swap(t_stack **stack);
void operation_push(t_stack **src, t_stack **dst);

#endif
