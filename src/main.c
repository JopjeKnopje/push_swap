/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/02/22 19:08:08 by joppe         ########   odam.nl         */
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

	int i = 1;
	head = 0;

	while (argc - 1)
	{
		long num = atol(argv[argc - 1]);
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

int is_sorted(t_stack *stack)
{
	t_stack *tmp = stack;
	while (tmp)
	{
		if (!(tmp->next))
			break;
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void bubblesort(t_stack *head) 
{ 
	t_stack *tmp;
	int swapped = 1;

	while (swapped)
	{
		swapped = 0;
		tmp = head;

		while (tmp->next)
		{
			if (tmp->nb > tmp->next->nb)
			{
				int x = tmp->nb;
				tmp->nb = tmp->next->nb;
				tmp->next->nb = x;
				swapped = 1;
			}
			tmp = tmp->next;
		}
	}
} 




t_stack *add_to_stack(int *arr, int size)
{
	t_stack *tmp = stack_new(arr[--size]);
	size--;
	while (size >= 0)
	{
		stack_add_front(&tmp, stack_new(arr[size]));
		size--;
	}
	return tmp;
}


// TODO understand this code
void apply_offset_test_arr(int *input, int *sorted, int size)
{
	int *tmplst = ft_calloc(size, sizeof(int));
	for (int i = 0; i < size; i++) 
		for (int j = 0; j < size; j++) 
		{
			if (input[i] == sorted[j])
			{
				// input[i] = j;
				tmplst[i] = j;
				printf("i %d | j %d | match input[%d] == sorted[%d]\n", i, j, input[i], sorted[j]);

			}

		}
	int i = 0;
	while (i < size) 
	{
		printf("%d \t%d \t%d\n", input[i], sorted[i], tmplst[i]);
		i++;
	}
	free(tmplst);
}

void apply_test_offset_lst(int *input, int *sorted, int size)
{
	t_stack *lst_input = add_to_stack(input, size);
	t_stack *lst_sorted = add_to_stack(sorted, size);
	t_stack *tmp_stack = NULL;
	print_stacks(lst_input, lst_sorted);

	t_stack *tmp_input = lst_input;
	t_stack *tmp_sorted = lst_sorted;

	int index = 0;
	while (tmp_input) 
	{
		tmp_sorted = lst_sorted;
		index = 0;
		while (tmp_sorted)
		{
			if (tmp_sorted->nb == tmp_input->nb)
			{
				// tmp_input->nb = index;
				if (!tmp_stack)
					tmp_stack = stack_new(index);
				else
					stack_add_back(&tmp_stack, stack_new(index));

			}

			tmp_sorted = tmp_sorted->next;	
			index++;
		}
		tmp_input = tmp_input->next;	
	}


	print_stacks(lst_input, tmp_stack);
	stack_free(&lst_input);
	stack_free(&lst_sorted);
	stack_free(&tmp_stack);
}





void apply_offset(t_stack *head_a, t_stack *head_copy)
{
	t_stack *tmp_input = head_a;
	t_stack *tmp_sorted = head_copy;

	int index = 0;
	while (tmp_input) 
	{
		tmp_sorted = head_copy;
		index = 0;
		while (tmp_sorted)
		{
			if (tmp_sorted->nb == tmp_input->nb)
				tmp_input->nb = index;	

			tmp_sorted = tmp_sorted->next;	
			index++;
		}
		tmp_input = tmp_input->next;	
	}
}


void do_sort(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int shift = 0;

}


int main(int argc, char *argv[])
{
	t_stack *head_a = NULL;
	t_stack *head_b = NULL;
	t_stack *head_copy = NULL;

	if (argc > 1 && parse_args(argv))
	{
		head_a = create_stack_a(argv, argc);
		head_copy = create_stack_a(argv, argc);
		if (is_sorted(head_a))
		{
			stack_free(&head_a);
			head_a = NULL;
		}
		if (!head_a)
		{
			printf("Error!\n");
			return 0;
		}

		// print_stacks(head_a, head_copy);
		// bubblesort(head_copy);
		// print_stacks(head_a, head_copy);
		// apply_offset(head_a, head_copy);
		// print_stacks(head_a, head_copy);
		int input[] = {87, -487, 781, -100, 101, 0, 1};
		int sorted[] = {-487, -100, 0, 1, 87, 101, 781};
		int size = 7;
		apply_test_offset_lst(input, sorted, size);
		apply_offset_test_arr(input, sorted, size);

		// print_stacks(head_a, head_copy);

		// print_stacks(head_a, head_b);

		// do_sort(&head_a, &head_b);
		// print_stacks(head_a, head_b);


		stack_free(&head_a);
		stack_free(&head_copy);
		stack_free(&head_b);
	}
	else
		printf("Error!\n");

	return (0);
}
