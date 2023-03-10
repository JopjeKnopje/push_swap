/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 14:24:01 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/10 02:02:14 by joppe         ########   odam.nl         */
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

char	**strjoin_free_2d(char **s_base, char **s_append)
{
	char	**s_joined;
	int		len_append;
	int		len_base;
	int		i;

	if (!s_append)
		return (NULL);
	len_base = ptr_arr_len(s_base);
	len_append = ptr_arr_len(s_append);
	s_joined = ft_calloc(len_append + len_base + 1, sizeof(char *));
	if (!s_joined)
	{
		free_split(s_base);
		free_split(s_append);
		return (NULL);
	}
	i = 0;
	while (s_base[i])
	{
		s_joined[i] = s_base[i];
		i++;
	}
	i = 0;
	while (s_append[i])
	{
		s_joined[i + len_base] = s_append[i];
		i++;
	}
	free(s_base);
	free(s_append);
	return (s_joined);
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

int	ptr_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

///////////////////////
// remove this stuff //
///////////////////////
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

