/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operatons.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 08:46:52 by joppe         #+#    #+#                 */
/*   Updated: 2023/04/13 13:45:08 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the top two numbers in a stack.
t_stack	*operation_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack) || !((*stack)->next))
		return (NULL);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	return (*stack);
}

// Top number in src goes to top of dst.
t_stack	*operation_push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!(*src))
		return (NULL);
	tmp = (*src);
	*src = (*src)->next;
	return (stack_add_front(dst, tmp));
}

// Top number in stack goes to bottom of stack.
t_stack	*operation_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return (NULL);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	stack_last(*stack)->next = tmp;
	return (*stack);
}

// Bottom number in stack goes to top of stack.
t_stack	*operation_reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;

	if (!(*stack) || !(*stack)->next)
		return (NULL);
	tmp = *stack;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		if (tmp->next && !(tmp->next->next))
			end = tmp;
		tmp = tmp->next;
	}
	end->next = NULL;
	tmp->next = (*stack);
	stack_add_front(stack, tmp);
	return (*stack);
}
