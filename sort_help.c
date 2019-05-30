/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_help.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 21:22:54 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/05/25 21:22:55 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_max(t_swap *s)
{
	int		i;
	int		max;

	i = 0;
	max = MIN_INT;
	while (i < s->stacksize)
	{
		if (s->stack[i] > max)
			max = s->stack[i];
		i++;
	}
	return (max);
}

int		find_min(t_swap *s)
{
	int		i;
	int		min;

	if (s->stacksize == 0)
		return (0);
	min = MAX_INT;
	i = 0;
	while (i < s->stacksize)
	{
		if (s->stack[i] < min)
			min = s->stack[i];
		i++;
	}
	return (min);
}

int		get_amount(t_swap *s, int median)
{
	int		i;

	if (s->stacksize == 0)
		return (0);
	i = 0;
	while (s->stack[0 + i] >= median && s->stack[0 + i] != 1)
		i++;
	return (i);
}

int		find_median(t_swap *s)
{
	int				i;
	long double		total;

	if (s->stacksize == 0)
		return (0);
	i = 0;
	total = 0;
	while (i < s->stacksize)
	{
		total += s->stack[i];
		i++;
	}
	return ((int)(total / (int)s->stacksize + 0.5));
}

int			find_pos(t_swap *s, int to_find)
{
	int		i;

	i = 0;
	while (i < s->stacksize)
	{
		if (s->stack[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}
