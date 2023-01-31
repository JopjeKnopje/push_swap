/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 18:41:31 by joppe         #+#    #+#                 */
/*   Updated: 2023/01/31 21:16:08 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include "libft.h"

typedef struct s_node
{
	int 			nb;
	struct s_node	*next;
}	t_node;


void 	stack_free(t_node **head);
void 	stack_add_front(t_node **lst, t_node *new);
void 	stack_free(t_node **head);
void 	stack_add_back(t_node **lst, t_node *new);
t_node	*stack_new(int nb);

#endif
