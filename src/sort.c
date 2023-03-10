/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 19:53:17 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/08 23:38:18 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO Maybe move node instead of value.
static	void	bubblesort(t_stack *head)
{
	t_stack	*head_tmp;
	int		swapped;
	int		tmp_val;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		head_tmp = head;
		while (head_tmp->next)
		{
			if (head_tmp->nb > head_tmp->next->nb)
			{
				tmp_val = head_tmp->nb;
				head_tmp->nb = head_tmp->next->nb;
				head_tmp->next->nb = tmp_val;
				swapped = 1;
			}
			head_tmp = head_tmp->next;
		}
	}
}

static	void	apply_offset(t_stack *head_a, t_stack *head_sorted)
{
	t_stack	*tmp;
	int		*isset;
	int		index;
	int		j;

	isset = ft_calloc(stack_size(head_a), sizeof(int));
	if (!isset)
		return ;
	index = 0;
	while (head_sorted)
	{
		j = 0;
		tmp = head_a;
		while (tmp)
		{
			if (tmp->nb == head_sorted->nb && !isset[j])
			{
				tmp->nb = index;
				isset[j] = 1;
			}
			tmp = tmp->next;
			j++;
		}
		head_sorted = head_sorted->next;
		index++;
	}
	free(isset);
}

static	void	sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_a_copy;
	int		shift;
	int		size_a;
	int		i;

	stack_a_copy = stack_dup(*stack_a);
	bubblesort(stack_a_copy);
	apply_offset(*stack_a, stack_a_copy);
	stack_free(stack_a_copy);
	shift = 0;
	while (!stack_is_sorted(*stack_a))
	{
		i = 0;
		size_a = stack_size(*stack_a);
		while (i < size_a)
		{
			if ((*stack_a)->nb >> shift & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			i++;
		}
		while ((*stack_b))
			pa(stack_a, stack_b);
		shift++;
	}
}

// TODO remove if statements for each case.
static	void	sort_3(t_stack **stack)
{
	int	nb[3] = {
		(*stack)->nb,
		(*stack)->next->nb,
		(*stack)->next->next->nb
	};
	if (nb[0] > nb[1] && nb[1] < nb[2] && nb[0] < nb[2])
	{
		sa(stack);
	}
	else if (nb[0] > nb[1] && nb[1] > nb[2] && nb[0] > nb[2])
	{
		sa(stack);
		rra(stack);
	}
	else if (nb[0] > nb[1] && nb[1] < nb[2] && nb[0] > nb[2])
	{
		ra(stack);
	}
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[0] < nb[2])
	{
		sa(stack);
		ra(stack);
	}
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[0] > nb[2])
	{
		rra(stack);
	}
}

static	int	find_rotates(t_stack *stack)
{
	int		i;
	t_stack	*max;

	i = 0;
	max = stack_max(stack);
	while (stack != max)
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
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}

void	do_sort(t_stack **head_a)
{
	t_stack	*head_b;
	int 	size;

	size = stack_size(*head_a);
	head_b = NULL;
	if (size == 2)
		sa(head_a);
	else if (stack_size(*head_a) <= 6)
		sort_small(head_a, &head_b);
	else
		sort_radix(head_a, &head_b);
	stack_free(head_b);
}
