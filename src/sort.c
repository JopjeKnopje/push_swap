/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 19:53:17 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/14 20:59:14 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// TODO remove if statements for each case.
static	void	sort_3(t_stack **s)
{
	if ((*s)->nb > (*s)->next->nb && (*s)->next->nb < (*s)->next->next->nb
		&& (*s)->nb < (*s)->next->next->nb)
		sa(s);
	else if ((*s)->nb > (*s)->next->nb && (*s)->next->nb > (*s)->next->next->nb
		&& (*s)->nb > (*s)->next->next->nb)
	{
		sa(s);
		rra(s);
	}
	else if ((*s)->nb > (*s)->next->nb && (*s)->next->nb < (*s)->next->next->nb
		&& (*s)->nb > (*s)->next->next->nb)
		ra(s);
	else if ((*s)->nb < (*s)->next->nb && (*s)->next->nb > (*s)->next->next->nb
		&& (*s)->nb < (*s)->next->next->nb)
	{
		sa(s);
		ra(s);
	}
	else if ((*s)->nb < (*s)->next->nb && (*s)->next->nb > (*s)->next->next->nb
		&& (*s)->nb > (*s)->next->next->nb)
		rra(s);
}

static	int	find_rotates(t_stack *stack)
{
	int		i;
	t_stack	*min;
	t_stack *tmp = stack;

	i = 0;
	min = stack_min(stack);
	while (stack != min)
	{
		i++;
		stack = stack->next;
	}

	int len = stack_size(tmp);
	if (i >= (len / 2) + (len % 2))
	{
		i = len - i + (len % 2);
		i = -i;
	}
	return (i);
}

static	void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	r_count;
	int	i;
	int	j;

	void (*rotate_func)(t_stack **) = &ra;

	i = 0;
	size = stack_size(*stack_a);
	while (i < size - 3)
	{
		r_count = find_rotates(*stack_a);
		if (r_count < 0) 
		{
			rotate_func = &rra;
			r_count = -r_count;
		}
		j = 0;
		while (j < r_count)
		{
			rotate_func(stack_a);
			j++;
		}
		pb(stack_a, stack_b);
		i++;
	}
	sort_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	do_sort(t_stack **head_a)
{
	t_stack	*head_b;
	int		size;

	head_b = NULL;
	size = stack_size(*head_a);
	if (size == 2)
		sa(head_a);
	else if (stack_size(*head_a) <= 6)
		sort_small(head_a, &head_b);
	else
		sort_radix(head_a, &head_b);
	stack_free(head_b);
}
