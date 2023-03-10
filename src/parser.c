/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/10 01:07:24 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static int	check_elements(char *argv[])
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

void print_split(char **s)
{
	int i = 0;
	while (s[i])
	{
		printf("[%s]\n", s[i]);
		i++;
	}
}

// TODO Input null checks.
// TODO Malloc protection.
char	**strjoin_free_2d(char **s_base, char **s_append)
{
	int		len_base;
	int		len_append;
	char 	**s_joined;

	len_base = 0;
	while (s_base[len_base]) 
		len_base++;	

	len_append = 0;
	while (s_append[len_append]) 
		len_append++;	
	
	s_joined = ft_calloc(len_append + len_base + 1, sizeof(char *));
	if (!s_joined)
		return (NULL);

	int i = 0;
	while (s_base[i]) 
	{
		s_joined[i]	= s_base[i];
		i++;
	}
	i = 0;
	while (s_append[i]) 
	{
		s_joined[i + len_base]	= s_append[i];
		i++;
	}

	free(s_base);
	free(s_append);
	return s_joined;
}

char **parse_args(char *argv[])
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
		i++;
	}
	passed = check_elements(args_base);
	if(!passed)
	{
		free_split(args_base);
		return (NULL);
	}
	return (args_base);
}


