/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operatons.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 08:46:52 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/08 19:19:41 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Swap the top two numbers in a stack.
void operation_swap(t_stack **stack)
{
	t_stack *tmp;

	if (!(*stack) || !((*stack)->next))
		return ;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}


// Top number in src goes to top of dst.
void operation_push(t_stack **src, t_stack **dst)
{
	t_stack *tmp;

	if (!(*src))
		return ;
	tmp = (*src);
	*src = (*src)->next;
	stack_add_front(dst, tmp);
}


// Top number in stack goes to bottom of stack.
void operation_rotate(t_stack **stack)
{
	t_stack *tmp;

	if (!(*stack))
		return;

	tmp = *stack;
	*stack = (*stack)->next;

	tmp->next = NULL;
	stack_last(*stack)->next = tmp;
}
