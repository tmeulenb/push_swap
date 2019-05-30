/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/30 15:14:36 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/05/30 15:14:36 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		help_display(void)
{
	ft_putstr("-----------------------------------------------------------\n");
	ft_putstr("Program = push_swap\n");
	ft_putstr("This program will sort a integerarray in ascending order.\n\n");
	ft_putstr("Usage = ./push_swap -flags 'SET_OF_INTEGERS'\n\n");
	ft_putstr("Available flags for push_swap:\n");
	ft_putstr("-checker = push_swap will work as checker too!.\n");
	ft_putstr("Program = checker\n");
	ft_putstr("This program will check the output of push_swap and return:\n");
	ft_putstr("OK is sorted, and KO if unsorted\n\n");
	ft_putstr("Usage =  ./push_swap -FLAGS 'SET_OF_INTEGERS'");
	ft_putstr(" | ./checker -flags 'SET_OF_INTEGERS'\n");
	ft_putstr("\nAvailable flags for checker:\n");
	ft_putstr("-v = display the stack after each operation.\n");
	ft_putstr("-o = visualize sorting algorithm.\n");
	ft_putstr("-x = display the amount of commands.\n");
	ft_putstr("-c = display the amount of commands per command.\n\n");
	ft_putstr("-----------------------------------------------------------\n");
	exit(1);
}

void		exec_flags_2(t_swap *a, t_swap *b)
{
	if (a->push_swap == 1 && a->push_swap_is_checker)
	{
		if (sorted(a) == 0 && b->stacksize == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return ;
}

void		exec_flags_1(t_swap *a, t_swap *b)
{
	int		total;
	int		rev_rotates;

	if (a->checker == 1 && a->display_amount_of_commands)
	{
		total = a->swaps + b->swaps + a->pushes + b->pushes
		+ a->rotates + b->rotates + a->rev_rotates + b->rev_rotates;
		printf("The total amount of commands: %d\n", total);
	}
	if (a->checker == 1 && a->display_amount_of_commands_per_command)
	{
		printf("The total amount of swaps: %d\n", a->swaps + b->swaps);
		printf("The total amount of pushes: %d\n", a->pushes + b->pushes);
		printf("The total amount of rotates: %d\n", a->rotates + b->rotates);
		rev_rotates = a->rev_rotates + b->rev_rotates;
		printf("The total amount of rev_rotates: %d\n", rev_rotates);
	}
}

void		exec_flags(t_swap *a, t_swap *b)
{
	exec_flags_1(a, b);
	exec_flags_2(a, b);
	return ;
}
