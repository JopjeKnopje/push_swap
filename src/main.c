/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/02/10 09:44:25 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>


t_stack *create_stack_a(char *argv[], int argc)
{
	t_stack *head; 
	head = NULL;

	while (argc - 1)
	{
		long num = ft_atol(argv[argc - 1]);
		if (num > INT_MAX || num < INT_MIN) 
		{
			stack_free(&head);
			return 0;
		}
		if (!head)
			head = stack_new(num);
		else
			stack_add_front(&head, stack_new(num));
		argc--;
	}
	return (head);
}

// testing to see if the stack operations work.
void do_sort(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ss(stack_a, stack_b);
}

// int main(int argc, char *argv[])
// {
// 	t_stack *head_a = NULL;
// 	t_stack *head_b = NULL;
// 	if (argc > 1 && parse_args(argv))
// 	{
// 		head_a = create_stack_a(argv, argc);
// 		if (!head_a)
// 		{
// 			printf("Error!\n");
// 			return 0;
// 		}
//
// 		print_stacks(head_a, head_b);
// 		do_sort(&head_a, &head_b);
// 		print_stacks(head_a, head_b);
//
// 		stack_free(&head_a);
// 		stack_free(&head_b);
// 	}
// 	else
// 		printf("Error!\n");
//
// 	return (0);
// }


int main (int argc, char *argv[])
{
	char *s[] = {
		"123",
		"0",
		"-0",
		"+0",
		"-922337203685477580",
		"-922337203685477581",
		"+9223372036854775807",
		"+9223372036854775808",
		"+9223372036854775809",
		NULL
	};

	int i = 0;
	int size = 0;
	while (s[size])
		size++;

	printf("input | atol | ft_atol\n");
	while (i < size)
	{
		long out_1 = atol(s[i]);
		long out_2 = ft_atol(s[i]);
		if (out_1 != out_2)
			printf("%s | %ld %6ld\n", s[i], out_1, out_2);
		i++;
	}
	return 0;
}

