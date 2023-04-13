/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 19:53:17 by joppe         #+#    #+#                 */
/*   Updated: 2023/04/13 14:25:28 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO Protect oeprations?
static	void	sort_3(t_stack **s)
{
	const int	nb1 = (*s)->nb;
	const int	nb2 = (*s)->next->nb;
	const int	nb3 = (*s)->next->next->nb;

	if (nb1 > nb2 && nb2 < nb3 && nb1 < nb3)
		sa(s);
	else if (nb1 > nb2 && nb2 > nb3 && nb1 > nb3)
	{
		sa(s);
		rra(s);
	}
	else if (nb1 > nb2 && nb2 < nb3 && nb1 > nb3)
		ra(s);
	else if (nb1 < nb2 && nb2 > nb3 && nb1 < nb3)
	{
		sa(s);
		ra(s);
	}
	else if (nb1 < nb2 && nb2 > nb3 && nb1 > nb3)
		rra(s);
}

static	int	find_rotates(t_stack *stack)
{
	int		i;
	int		size;
	t_stack	*min;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	min = stack_min(tmp);
	while (tmp != min)
	{
		tmp = tmp->next;
		i++;
	}
	size = stack_size(stack);
	if (i > size / 2)
		i = -(size - i);
	return (i);
}

// TODO Protect rotate_func.
static	void	smart_rotate(t_stack **stack)
{
	int		i;
	int		r_count;
	int		(*rotate_func)(t_stack **);

	r_count = find_rotates(*stack);
	if (r_count < 0)
	{
		rotate_func = &rra;
		r_count = -r_count;
	}
	else
		rotate_func = &ra;
	i = 0;
	while (i < r_count)
	{
		rotate_func(stack);
		i++;
	}
}

static	int	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;

	i = 0;
	size = stack_size(*stack_a);
	while (i < size - 3)
	{
		smart_rotate(stack_a);
		if (stack_is_sorted(*stack_a))
			break ;
		if (!pb(stack_a, stack_b))
			return (0);
		i++;
	}
	sort_3(stack_a);
	while (*stack_b)
	{
		if (!pa(stack_a, stack_b))
			return (0);
	}
	return (1);
}

int	do_sort(t_stack **head_a)
{
	t_stack	*head_b;
	int		ret_val;
	int		size;

	ret_val = 1;
	head_b = NULL;
	size = stack_size(*head_a);
	if (size == 2)
		ret_val = sa(head_a);
	else if (size > 2 && size <= 6)
		ret_val = sort_small(head_a, &head_b);
	else if (size > 6)
		ret_val = sort_radix(head_a, &head_b);
	stack_free(head_b);
	return (ret_val);
}
