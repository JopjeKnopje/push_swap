/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operatons.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 08:46:52 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/07 14:46:15 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	// isolate node from src

	tmp = (*src);
	*src = (*src)->next;
	// stack_add_front
	stack_add_front(dst, tmp);


}
