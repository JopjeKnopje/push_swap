/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 16:39:57 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/10 01:59:14 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifdef BUILD_TESTER
# define ft_putstr_fd(s, fd) (0)
#endif

// Swap the top two numbers in A
void	sa(t_stack **stack_a)
{
	operation_swap(stack_a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

// Top number in B goes to top of A
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	operation_push(stack_b, stack_a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

// Top number in A goes to top of B
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	operation_push(stack_a, stack_b);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}

// Top number in A goes to bottom of A
void	ra(t_stack **stack_a)
{
	operation_rotate(stack_a);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

// Bottom number in A goes to top of A
void	rra(t_stack **stack_a)
{
	operation_reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}
