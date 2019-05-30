/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extra.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/11 14:20:55 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/05/11 14:21:12 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				sorted(t_swap *a)
{
	int		i;

	i = 0;
	while (i < a->stacksize - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void			error(int choice)
{
	if (choice == 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (choice == 1)
	{
		ft_putstr("This is not a valid flag.\n");
		ft_putstr("Use -v for stack display between commands\n");
		ft_putstr("Use -x for total amount of commands\n");
		ft_putstr("Use -c for total of each command\n");
		ft_putstr("Use -o to visualize sorting\n");
		ft_putstr("Use -n to only do a certain amount of commands\n");
		ft_putstr("		Example = -99\n");
		ft_putstr("Use -checker to use push_swap as checker directly\n");
		ft_putstr("Use --help for help\n");
		exit(1);
	}
	if (choice == 2)
	{
		ft_putstr("No integers as argument.\n");
		ft_putstr("Usage: ./program_name -flags 'integers'\n");
		exit(1);
	}
}

void			show_stacks(t_swap *a, t_swap *b)
{
	int		i;

	i = 0;
	write(1, "\n--------------A--------------------------\n", 43);
	while (i < a->stacksize)
	{
		ft_putnbr(a->stack[i]);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n--------------B--------------------------\n", 43);
	i = 0;
	while (i < b->stacksize)
	{
		ft_putnbr(b->stack[i]);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n\n", 2);
}
