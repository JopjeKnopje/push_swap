/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:57:28 by joppe         #+#    #+#                 */
/*   Updated: 2023/04/13 10:10:33 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (!stack->next)
			break ;
		stack = stack->next;
	}
	return (stack);
}

t_stack	*stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !(*stack) || !new)
		return (NULL);
	if (!(*stack))
	{
		*stack = new;
		last = new;
	}
	else
	{
		last = stack_last(*stack);
		last->next = new;
	}
	return (last);
}

t_stack	*stack_add_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return (NULL);
	if (!stack && new)
	{
		free(new);
		return (NULL);
	}
	if (!(*stack))
	{
		*stack = new;
		new->next = NULL;
		return (*stack);
	}
	new->next = *stack;
	*stack = new;
	return (*stack);
}

t_stack	*stack_new(int nb)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->next = NULL;
	return (node);
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
