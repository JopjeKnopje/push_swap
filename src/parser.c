/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/07 20:03:30 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	parse_args(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 1;
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
