/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:57:28 by joppe         #+#    #+#                 */
/*   Updated: 2023/01/31 21:23:09 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>


void stack_free(t_node **head)
{
	t_node *tmp;
	while (*head)
	{
		if (!(*head)->next)
			break ;
		
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

t_node	*stack_last(t_node *stack)
{
	t_node	*tmp;

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

void 	stack_add_back(t_node **stack, t_node *new)
{
	t_node	*last;

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

void 	stack_add_front(t_node **stack, t_node *new)
{
	if (!stack || !new)
		return ;

	new->next = *stack;
	*stack = new;
}

t_node	*stack_new(int nb)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->next = NULL;
	return (node);
}
