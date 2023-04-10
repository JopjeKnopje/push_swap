/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/04/10 11:25:14 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	is_str_num(char *s)
{
	int	i;
	int	has_sign;

	i = 0;
	has_sign = 0;
	while (s[i] == '-' || s[i] == '+')
		i++;
	has_sign = i;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (!(i == has_sign));
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
			if (!ft_strncmp(strings[i], strings[j], 11))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_elements(char *argv[])
{
	int	i;

	i = 0;
	if (!argv || has_dupes(argv))
		return (0);
	while (argv[i])
	{
		if (!is_str_num(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**parse_args(char *argv[])
{
	char	**args_base;
	char	**split;
	int		i;

	args_base = ft_calloc(1, sizeof(char *));
	if (!args_base)
		return (NULL);
	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
		{
			free_split(args_base);
			return (NULL);
		}
		args_base = strjoin_free_2d(args_base, split);
		if (!args_base)
			return (NULL);
		i++;
	}
	if (args_base && !check_elements(args_base))
	{
		free_split(args_base);
		return (NULL);
	}
	return (args_base);
}
