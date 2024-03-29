/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 14:24:01 by jboeve        #+#    #+#                 */
/*   Updated: 2023/04/13 21:36:15 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static	char	**free_ptr2(char **p1, char **p2)
{
	free(p1);
	free(p2);
	return (NULL);
}

t_stack	*create_stack_a(char *args[], int len)
{
	t_stack	*head;
	long	num;

	len--;
	head = NULL;
	while (len >= 0)
	{
		num = ft_atol(args[len]);
		if (num > INT_MAX || num < INT_MIN)
			return (stack_free(head));
		if (!head)
		{
			head = stack_new(num);
			if (!head)
				return (NULL);
		}
		else
		{
			if (!stack_add_front(&head, stack_new(num)))
				return (stack_free(head));
		}
		len--;
	}
	return (head);
}

char	**strjoin_free_2d(char **s_base, char **s_append)
{
	char	**s_joined;
	int		len_base;
	int		i;

	if (!s_append)
		return (NULL);
	len_base = str_arr_len(s_base);
	s_joined = ft_calloc(str_arr_len(s_append) + len_base + 1, sizeof(char *));
	if (!s_joined)
		return (free_split(s_base), free_split(s_append), NULL);
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
	free_ptr2(s_base, s_append);
	return (s_joined);
}

int	free_split(char **s_split)
{
	int	i;

	if (!s_split && !(*s_split))
		return (0);
	i = 0;
	while (s_split[i])
	{
		free(s_split[i]);
		i++;
	}
	free(s_split);
	return (0);
}

int	str_arr_len(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}
