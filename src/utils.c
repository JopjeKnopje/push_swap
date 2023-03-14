/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 14:24:01 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/14 18:29:49 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack_a(char *args[], int len)
{
	t_stack	*head;
	long	num;

	head = NULL;
	while (len >= 0)
	{
		num = ft_atol(args[len]);
		if (num > INT_MAX || num < INT_MIN)
		{
			stack_free(head);
			return (NULL);
		}
		if (!head)
			head = stack_new(num);
		else
			stack_add_front(&head, stack_new(num));
		len--;
	}
	return (head);
}

static	char	**free_2d_ptr(char **p1, char **p2)
{
	free(p1);
	free(p2);
	return (NULL);
}

int	ptr_arr_len(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

char	**strjoin_free_2d(char **s_base, char **s_append)
{
	char	**s_joined;
	int		len_base;
	int		i;

	if (!s_append)
		return (NULL);
	len_base = ptr_arr_len(s_base);
	s_joined = ft_calloc(ptr_arr_len(s_append) + len_base + 1, sizeof(char *));
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
