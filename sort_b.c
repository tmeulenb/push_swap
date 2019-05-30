/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 21:21:25 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/05/25 21:21:25 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_median_using_limit(t_swap *s, int limit)
{
	int			i;
	float		total;

	if (s->stacksize == 0)
		return (0);
	i = 0;
	total = 0;
	while (s->stack[0 + i] >= limit && s->stack[0 + i] != 1)
	{
		total += s->stack[0 + i];
		i++;
	}
	return ((int)(total / (int)s->stacksize + 0.5));
}


void		split_to_b(t_swap *a, t_swap *b, int median, int stacksize)
{
	int		i;

	i = 0;
	while (i < stacksize)
	{
		if (a->stack[0] < median)
			ft_push(a, b, "pb\n");
		else
			ft_rotate(a, "ra\n");
		i++;
	}
}

void		split_back_to_b(t_swap *a, t_swap *b, int max)
{
	while (a->stack[0] <= max && a->stack[0] != a->lowest_int)
	{
		if (a->stack[0] == find_next(a, a->stack[a->stacksize - 1]))
			ft_rotate(a, "ra\n");
		else
			ft_push(a, b, "pb\n");
	}
	if (find_min(b) == find_next(a, a->stack[a->stacksize - 1]))
		quick_sort_algo(a, b);
}

void		back_track_quicksort_help(t_swap *a, t_swap *b, int median, int *x)
{
	if (a->stack[0] >= median)
	{
		ft_rotate(a, "ra\n");
		++*x;
	}
	else
		ft_push(a, b, "pb\n");
}

void		back_track_quicksort(t_swap *a, t_swap *b, int max)
{
	int		x;
	int		i;
	int		median;

	median = find_median_using_limit(a, max);
	x = 0;
	while (a->stack[0] <= max && a->stack[0] != a->lowest_int)
		back_track_quicksort_help(a, b, median, &x);
	i = 0;
	while (i < x)
	{
		if (b->stack[0] != find_max(b))
			do_operations_for_both(a, b, 3);
		else
			ft_rev_rotate(a, "rra\n");
		i++;
	}
	if (find_min(b) == find_next(a, a->stack[a->stacksize - 1]) && x > 0)
		quick_sort_algo(a, b);
}
