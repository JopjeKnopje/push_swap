/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/08 17:05:28 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static	int	is_num_str(char *s)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static	int	has_dupes(char *strings[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (strings[i])
	{
		j = i + 1;
		while (strings[j])
		{
			if (!ft_strncmp(strings[i], strings[j], 10))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_elements(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (has_dupes(argv))
		return (0);
	while (argv[i])
	{
		if (!is_num_str(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

char **parse_args(char *argv[])
{
	char **split;
	int ret;

	if (!argv[1])
		return NULL;

	if (ft_strchr(argv[1], ' '))
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return NULL;
		ret = check_elements(split);
		if (!ret)
			free_split(split);
	}
	else
	{
		split = argv + 1;
		ret = check_elements(split);
		if (!ret)
			return NULL;
	}
	return (split);
}
