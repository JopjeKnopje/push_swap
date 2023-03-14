/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 19:53:17 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/14 18:36:57 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	i = 0;
	min = stack_min(stack);
	while (stack != min)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

static	void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	r_count;
	int	i;
	int	j;

	i = 0;
	size = stack_size(*stack_a);
	while (i < size - 3)
	{
		r_count = find_rotates(*stack_a);
		j = 0;
		while (j < r_count)
		{
			ra(stack_a);
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
