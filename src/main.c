/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 09:21:42 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/09 09:56:15 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

void do_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp = *stack_a;
	for (int i = 0; i <= 8; i++) 
	{
		operation_push(stack_a, stack_b);
	}
	operation_reverse_rotate(stack_b);
}

// !(!tmp_a && !tmp_b) == (tmp_a || tmp_b) WTF?

#define BIT_LEN 4

int main (int argc, char *argv[])
{
	int i = 0;
	while (i < BIT_LEN)
	{
		int bit_1 = (i & 0b00000001);
		int bit_2 = (i & 0b00000010) >> 1;
		printf("%d %d\n", bit_1, bit_2);
		i++;
	}
}


// int main (int argc, char *argv[])
// {
// 	srand(time(NULL));
//
// 	t_stack *stack_a = NULL;
// 	t_stack *stack_b = NULL;
// 	int i = 1;
// 	while (i <= 10)
// 	{
// 		stack_add_back(&stack_a, stack_new(i));
// 		i++;
// 	}
//
// 	print_stacks(stack_a, stack_b);
// 	do_sort(&stack_a, &stack_b);
// 	print_stacks(stack_a, stack_b);
//
//
// 	stack_free(&stack_a);
// 	stack_free(&stack_b);
//
// 	return 0;
// }
