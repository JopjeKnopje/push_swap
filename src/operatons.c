/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operatons.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 08:46:52 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/06 09:36:45 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


// Swap the top two numbers in a stack.
void operation_swap(t_stack **stack)
{
	t_stack *tmp;

	
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = tmp;

}

