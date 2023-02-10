/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/02/10 12:26:31 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>


// TODO Add to libft
int is_num_str(char *s)
{
	int i = 0;
	int counter = 0;
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

// TODO Check for duplicates
int parse_args(char *argv[])
{
	int i = 1;

	while (argv[i]) 
	{
		if (!is_num_str(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
      
t_stack *create_stack_a(char *argv[], int argc)
{
	t_stack *head; 

	int i = 1;
	head = 0;

	// if argv is 0 we get error?
	while (argv[i])
	{
		long num = atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN) 
		{
			stack_free(&head);
			return 0;
		}
		if (!head)
			head = stack_new(num);
		else
			// TODO Instead of stack_add_back reverse iterate over the argv array.
			stack_add_back(&head, stack_new(num));
		i++;
	}
	return (head);
}


int calculate_median(t_stack *stack)
{
	t_stack *tmp = stack;
	int median = stack->nb;
	int mid = stack_size(stack) / 2;
	int i = 0;

	while (tmp)
	{
		if (i == mid)
			median += tmp->nb;
		if (!tmp->next)
			break;
		i++;
		tmp = tmp->next;
	}
	median += tmp->nb;
	median /= 3;
	return median;
}

t_stack *find_median(t_stack *stack, int median, int range)
{
	t_stack *tmp = stack;

	static int counter = 0;
	static int printed = 0;
	counter++;
	
	while (tmp)
	{
		if (tmp->nb >= median - range && tmp->nb <= median + range)
			return tmp;
		tmp = tmp->next;
	}
	t_stack *med = find_median(stack, median, range + 1);

	if (med && !printed)
	{
		printf("%s call %d\n", __func__, counter);
		printed = 1;
	}

	return (med);
}


// testing to see if the stack operations work.
void do_sort(t_stack **stack_a, t_stack **stack_b)
{
	int num = calculate_median(*stack_a);
	t_stack *med = find_median(*stack_a, num, 0);
	if (!med)
		printf("med not found\n");
	else
		printf("median %d\n", med->nb);

}


int main(int argc, char *argv[])
{
	t_stack *head_a = NULL;
	t_stack *head_b = NULL;
	if (argc > 1 && parse_args(argv))
	{
		// add to list
		head_a = create_stack_a(argv, argc);
		if (!head_a)
		{
			printf("Error!\n");
			return 0;
		}

		// print_stacks(head_a, head_b);
		do_sort(&head_a, &head_b);
		// print_stacks(head_a, head_b);

		stack_free(&head_a);
		stack_free(&head_b);
	}
	else
		printf("Error!\n");

	return (0);
}
