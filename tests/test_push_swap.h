/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_push_swap.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 18:05:16 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/03 18:07:08 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"


char	**free_all(char **s_split, int i);
char 	*stack_to_str(t_stack *stack)
