/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/11 17:40:52 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/05/11 17:41:08 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap		*pw_newlist(void)
{
	t_swap			*list;

	list = (t_swap *)ft_memalloc(sizeof(t_swap));
	if (!list)
		return (NULL);
	return (list);
}

void		initialize_struct(t_swap *a, int argc, char **argv)
{
	a->argc = argc;
	a->argv = argv;
	a->stack = malloc(sizeof(int) * a->argc - 1);
	a->sorted_stack = malloc(sizeof(int) * a->argc - 1);
	a->stacksize = 0;
	a->push_swap = 0;
	a->checker = 0;
	a->display_stack = 0;
	a->visualize_sorting = 0;
	a->push_swap_is_checker = 0;
	a->display_amount_of_commands = 0;
	a->display_amount_of_commands_per_command = 0;
	a->help_display = 0;
	a->amount_of_flags = 0;
	a->swaps = 0;
	a->pushes = 0;
	a->rotates = 0;
	a->rev_rotates = 0;
	return ;
}

void		initialize_variables(t_swap *a, t_swap *b)
{
	int		lowest;

	lowest = find_min(a);
	a->lowest_int = lowest;
	b->lowest_int = lowest;
	a->push_swap = 1;
	b->push_swap = 1;
}

void		make_stacks(t_swap *a)
{
	int		i;
	int		argument_pos;

	argument_pos = 1;
	i = 0;
	argument_pos += check_flags(a, argument_pos);
	while (argument_pos < a->argc)
	{
		check_string_for_non_numeric(a->argv[argument_pos]);
		check_value(ft_atoi(a->argv[argument_pos]));
		check_reoccurence(a, ft_atoi(a->argv[argument_pos]));
		a->stack[i] = ft_atoi(a->argv[argument_pos]);
		i++;
		a->stacksize++;
		argument_pos++;
	}
	return ;
}
