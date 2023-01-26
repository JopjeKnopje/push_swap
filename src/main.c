/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/01/26 23:50:07 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>


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

int parse_args(char *argv[])
{
	int i = 1;

	// while (i < argc) 
	while (argv[i]) 
	{
		if (!is_num_str(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
      
t_list *create_stack_a(char *argv[])
{
	t_list *head = ft_lstnew(argv[1]);

	int i = 1;
	while (argv[i])
	{
		ft_lstadd_front(&head, ft_lstnew(argv[i]));
		// ft_lstadd_back(&head, ft_lstnew(argv[i]));
		i++;
	}
	return (head);
}

void print_list(t_list *head)
{
	t_list *tmp = head;
	while (tmp)
	{
		if (!tmp->next)
			break ;

		printf("%s\n", (char *) tmp->content);

		tmp = tmp->next;
	}
}

int main (int argc, char *argv[])
{
	t_list *head_a;
	if (argc > 1 && parse_args(argv))
	{
		// add to list
		 head_a = create_stack_a(argv);
	}
	else
		printf("Error!\n");

	print_list(head_a);
	return (0);
}
