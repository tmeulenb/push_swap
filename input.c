/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/11 16:30:46 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/05/11 16:31:00 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_string_for_non_numeric(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			error(0);
		i++;
	}
	return ;
}

void		check_value(long long nbr)
{
	if (nbr < -2147483648 || nbr > 2147483647)
		error(0);
	return ;
}

void		check_reoccurence(t_swap *a, int reocurring)
{
	int		i;

	i = 0;
	while (i < a->stacksize)
	{
		if (a->stack[i] == reocurring)
			error(0);
		i++;
	}
	return ;
}

void		initialize_flags(t_swap *a, char *flag)
{
	if (a->checker && strcmp("-x", flag) == 0)
		a->display_amount_of_commands = 1;
	if (a->checker && strcmp("-c", flag) == 0)
		a->display_amount_of_commands_per_command = 1;
	if (a->checker && strcmp("-v", flag) == 0)
		a->display_stack = 1;
	if (a->checker && strcmp("-o", flag) == 0)
		a->visualize_sorting = 1;
	if (strcmp("-checker", flag) == 0)
		a->push_swap_is_checker = 1;
}

int			check_flags(t_swap *a, int pos)
{
	int		flags;

	flags = 0;
	while (pos < a->argc)
	{
		if (strcmp("--help", a->argv[pos]) == 0)
			help_display();
		else if (strcmp("-", a->argv[pos]) == 0)
			error(1);
		if (ft_strstr("-v-o-x-c-checker ", a->argv[pos]))
		{
			initialize_flags(a, a->argv[pos]);
			flags++;
		}
		else if (a->argv[pos][0] == '-' && !ft_isdigit(a->argv[pos][1]))
			error(1);
		pos++;
	}
	return (flags);
}
