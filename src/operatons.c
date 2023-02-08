/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operatons.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 08:46:52 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/08 09:57:08 by joppe         ########   odam.nl         */
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
// TODO doens't set the next pointer of the last element
void operation_push(t_stack **src, t_stack **dst)
{
	t_stack *tmp;

	// TODO Handle if not *stack->next.
	// TODO Handle (prob malloc) if there is no *dst
	// TODO When we want to add the last element of src, we loose the next ptr.

	tmp = (*src);
	// if end of src stack
	if ((*src)->next)
	{
		// return ;
	}
	*src = (*src)->next;
	stack_add_front(dst, tmp);


}
