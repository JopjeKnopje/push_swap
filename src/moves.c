/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 16:39:57 by joppe         #+#    #+#                 */
/*   Updated: 2023/04/12 22:58:28 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the top two numbers in A
int	sa(t_stack **stack_a)
{
	if (operation_swap(stack_a))
	{
		ft_putstr_fd("sa\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

// Top number in B goes to top of A
int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (operation_push(stack_b, stack_a))
	{
		ft_putstr_fd("pa\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

// Top number in A goes to top of B
int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (operation_push(stack_a, stack_b))
	{
		ft_putstr_fd("pb\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

// Top number in A goes to bottom of A
int	ra(t_stack **stack_a)
{
	if (operation_rotate(stack_a))
	{
		ft_putstr_fd("ra\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

// Bottom number in A goes to top of A
int	rra(t_stack **stack_a)
{
	if (operation_reverse_rotate(stack_a))
	{
		ft_putstr_fd("rra\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}
