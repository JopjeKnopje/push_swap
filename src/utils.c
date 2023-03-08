/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 14:24:01 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/08 17:26:35 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack_a(char *argv[], int argc)
{
	t_stack	*head;
	long	num;

	head = 0;
	int i = 0;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			stack_free(head);
			return (0);
		}
		if (!head)
			head = stack_new(num);
		else
			// stack_add_front(&head, stack_new(num));
			stack_add_back(&head, stack_new(num));
		i++;
	}
	return (head);
}

char	**free_split(char **s_split)
{
	int i = 0;
	while (s_split[i])
	{
		free(s_split[i]);
		i++;
	}
	free(s_split);
	return (NULL);
}

///////////////////////
// remove this stuff //
///////////////////////
// TODO Support negative number
char	*bin_to_str(int nb)
{
	int		size;
	int		tmp;
	char	*s;

	size = 0;
	tmp = nb;
	while (tmp)
	{
		tmp >>= 1;
		size++;
	}
	s = ft_calloc(size + 1, sizeof(char));
	if (!s)
		return (s);
	while (size > 0)
	{
		size--;
		s[size] = (nb & 1) + '0';
		nb >>= 1;
	}
	return (s);
}

void	print_stacks(t_stack *head_a, t_stack *head_b)
{
	t_stack *tmp_a = head_a;
	t_stack *tmp_b = head_b;

	int stack_a_len = stack_size(head_a);
	int stack_b_len = stack_size(head_b);

	while (tmp_a || tmp_b)
	{
		if (tmp_a)
			printf("stack_a %4d\t", tmp_a->nb);
		else 
			printf("\t\t");
		if (tmp_b)
			printf("| stack_b %4d\n", tmp_b->nb);
		else
			printf("\n");
		
		if (tmp_a && tmp_a->next)
			tmp_a = tmp_a->next;
		else
		 	tmp_a = NULL;
		if (tmp_b && tmp_b->next)
			tmp_b = tmp_b->next;
		else
		 	tmp_b = NULL;
	}
	printf("==============================\n");
}

