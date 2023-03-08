/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 18:04:49 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/08 09:34:29 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "test_push_swap.h"

char	**test_free_all(char **s_split, int i)
{
	while (i--)
		free(s_split[i]);
	free(s_split);￼
	return (NULL);
}
￼
char *stack_to_str(t_stack *stack)
{
	int size = stack_size(stack);
￼
	// sure we can calculate the buf￼fersize but just hardcode it.
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

