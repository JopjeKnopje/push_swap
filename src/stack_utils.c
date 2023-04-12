/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 20:06:03 by joppe         #+#    #+#                 */
/*   Updated: 2023/04/12 23:04:08 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_dup(t_stack *head)
{
	t_stack	**last;
	t_stack	*new;
	t_stack	*tmp;

	tmp = head;
	if (!head)
		return (NULL);
	new = stack_new(tmp->nb);
	if (!new)
		return (NULL);
	last = &new;
	tmp = tmp->next;
	while (tmp)
	{
		if (!stack_add_back(last, stack_new(tmp->nb)))
		{
			stack_free(*last);
			return (NULL);
		}
		last = &(*last)->next;
		tmp = tmp->next;
	}
	return (new);
}

t_stack	*stack_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->nb < min->nb)
			min = stack;
		stack = stack->next;
	}
	return (min);
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
