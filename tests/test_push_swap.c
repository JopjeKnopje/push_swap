/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_push_swap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 11:32:55 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/07 11:32:56 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"


char	**free_all(char **s_split, int i)
{
	while (i--)
		free(s_split[i]);
	free(s_split);
	return (NULL);
}

char *stack_to_str(t_stack *stack)
{
	int size = stack_size(stack);

	// sure we can calculate the buffersize but just hardcode it.
	char *s = ft_calloc(64, sizeof(char));
	char *s_start = s;

	while (stack)
	{
		if (s_start == s)
			sprintf(s, "%d", stack->nb);
		else
			sprintf(s, " %d", stack->nb);
		stack = stack->next;	
		s = s_start + ft_strlen(s_start);
	}
	return s_start;
}

