/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 20:06:03 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/07 20:25:24 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO Optimize
t_stack	*stack_dup(t_stack *head)
{
	t_stack	*new;
	t_stack	**last;
	t_stack	*tmp;

	new = NULL;
	tmp = head;
	if (!head)
		return (NULL);
	while (tmp)
	{
		if (!new)
		{
			new = stack_new(tmp->nb);
			last = &new;
		}
		else
		{
			stack_add_front(last, stack_new(tmp->nb));
			last = &(*last)->next;
		}
		tmp = tmp->next;
	}
	operation_reverse_rotate(&new);
	return (new);
}

t_stack	*stack_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->nb > max->nb)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

int	stack_is_sorted(t_stack *stack)
{
	while (stack)
	{
		if (!(stack->next))
			break ;
		if ((stack->nb > stack->next->nb))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	stack_free(t_stack *head)
{
	t_stack	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
