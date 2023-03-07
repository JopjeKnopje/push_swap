/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:57:28 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/07 20:06:43 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void 	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!(*stack))
		*stack = new;
	else
	{
		last = stack_last(*stack);
		last->next = new;
	}
}

void 	stack_add_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;

	new->next = *stack;
	*stack = new;
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
