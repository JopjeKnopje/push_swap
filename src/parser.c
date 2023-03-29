/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/29 17:01:09 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	is_num_str(char *s)
{
	int	i;

	i = 0;
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

char	**parse_args(char *argv[])
{
	char	**args_base;
	char	**split;
	int		passed;
	int		i;

	args_base = ft_calloc(1, sizeof(char *));
	if (!args_base)
		return (NULL);
	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		args_base = strjoin_free_2d(args_base, split);
		if (!args_base)
			break ;
		i++;
	}
	passed = check_elements(args_base);
	if (!passed || !split)
	{
		free_split(args_base);
		return (NULL);
	}
	return (args_base);
}
