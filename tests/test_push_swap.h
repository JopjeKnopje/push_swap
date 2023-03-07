/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_push_swap.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 11:33:02 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/07 11:47:19 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/logging.h>
#include <criterion/criterion.h>
#include <criterion/internal/test.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/new_asserts.h>
#include "push_swap.h"
#include "libft.h"



void assert_sort_small(char *s, char *expected);


///////////////////////
// Utility functions //
///////////////////////
char	**free_all(char **s_split, int i);
char *stack_to_str(t_stack *stack);
