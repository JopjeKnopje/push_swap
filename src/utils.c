/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 14:24:01 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/13 23:52:25 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

t_stack	*create_stack_a(char *argv[], int argc)
{
	t_stack	*head;
	long	num;
	int i = 0;

	head = NULL;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		printf("argv[argc - 1] %s\n", argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			stack_free(head);
			return (NULL);
		}
		if (!head)
			head = stack_new(num);
		else
			stack_add_front(&head, stack_new(num));
		i++;
	}
	return (head);
}

char **free_2d_ptr(char **p1, char **p2)
{
	free(p1);
	free(p2);
	return (NULL);
}

char	**strjoin_free_2d(char **s_base, char **s_append)
{
	char	**s_joined;
	int		len_append;
	int		len_base;
	int		i;


	if (!s_append)
		return (NULL);
	len_base = ft_strlen((const char *) s_base);
	s_joined = ft_calloc(ft_strlen((const char *) s_append) + len_base + 1, sizeof(char *));
	if (!s_joined)
		return (free_2d_ptr(s_base, s_append));
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
	free_2d_ptr(s_base, s_append);
	return (s_joined);
}

char	**free_split(char **s_split)
{
	int	i;

	i = 0;
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

