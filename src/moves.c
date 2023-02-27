/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 16:39:57 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/26 21:04:38 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


// #define printf(fmt, ...) (0)

// Swap the top two numbers in A
void sa(t_stack **stack_a)
{
	operation_swap(stack_a);
	printf("%s\n", __func__);
}

// Swap the top two numbers in B
void sb(t_stack **stack_b)
{
	operation_swap(stack_b);
	printf("%s\n", __func__);
}

// sa + sb
void ss(t_stack **stack_a, t_stack **stack_b)
{
	operation_swap(stack_a);
	operation_swap(stack_b);
	printf("%s\n", __func__);
}

// Top number in B goes to top of A
void pa(t_stack **stack_a, t_stack **stack_b)
{
	operation_push(stack_b, stack_a);
	printf("%s\n", __func__);
}

// Top number in A goes to top of B
void pb(t_stack **stack_a, t_stack **stack_b)
{
	operation_push(stack_a, stack_b);
	printf("%s\n", __func__);
}

// Top number in A goes to bottom of A
void ra(t_stack **stack_a)
{
	operation_rotate(stack_a);
	printf("%s\n", __func__);
}

// Top number in B goes to bottom of B
void rb(t_stack **stack_b)
{
	operation_rotate(stack_b);
	printf("%s\n", __func__);
}

// ra + rb
void rr(t_stack **stack_a, t_stack **stack_b)
{
	operation_rotate(stack_a);
	operation_rotate(stack_b);
	printf("%s\n", __func__);
}

// Bottom number in A goes to top of A
void rra(t_stack **stack_a)
{
	operation_reverse_rotate(stack_a);
	printf("%s\n", __func__);
}

// Bottom number in B goes to top of B
void rrb(t_stack **stack_b)
{
	operation_reverse_rotate(stack_b);
	printf("%s\n", __func__);
}

// rra + rrb
void rrr(t_stack **stack_a, t_stack **stack_b)
{
	operation_rotate(stack_a);
	operation_rotate(stack_b);
	printf("%s\n", __func__);
}
