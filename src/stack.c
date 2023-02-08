/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:57:28 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/08 19:17:58 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>


void stack_free(t_stack **head)
{
	t_stack *tmp;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
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
