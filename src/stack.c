/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:57:28 by joppe         #+#    #+#                 */
/*   Updated: 2023/01/31 21:15:56 by joppe         ########   odam.nl         */
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

void 	stack_add_back(t_node **lst, t_node *new)
{
	t_node *tmp;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	tmp = *lst;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	tmp->next = new;
}

void 	stack_add_front(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;

	new->next = *lst;
	*lst = new;
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
