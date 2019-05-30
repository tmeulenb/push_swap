/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_a.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 21:21:13 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/05/25 21:21:13 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sort(t_swap *s)
{
	int		i;

	if (s->stacksize == 0)
		return (1);
	i = s->stacksize - 1;
	while (i > 0)
	{
		if (s->stack[i - 1] < s->stack[i])
			return (0);
		i--;
	}
	return (1);
}

void	get_median_to_a(t_swap *a, t_swap *b)
{
	int		max;
	int		pos;

	while (b->stacksize > 0)
	{
		max = find_max(b);
		if (max == b->stack[0])
			ft_push(b, a, "pa\n");
		else
		{
			pos = find_pos(b, max);
			if (b->stack[0] == find_next(a, a->stack[a->stacksize - 1])
										|| b->stack[0] == a->lowest_int)
			{
				ft_push(b, a, "pa\n");
				ft_rotate(a, "ra\n");
			}
			else
				smart_rotate(b, pos, 'b');
		}
	}
}

void	split_to_a(t_swap *a, t_swap *b, int median, int stacksize)
{
	while (stacksize > 0)
	{
		if (b->stacksize < 13)
			get_median_to_a(a, b);
		else
		{
			if (b->stack[0] >= median)
				ft_push(b, a, "pa\n");
			else
			{
				if (b->stack[0] == find_next(a, a->stack[a->stacksize - 1])
											|| b->stack[0] == a->lowest_int)
				{
					ft_push(b, a, "pa\n");
					ft_rotate(a, "ra\n");
				}
				else
					ft_rotate(b, "rb\n");
			}
		}
		stacksize--;
	}
}

void	quick_sort_algo(t_swap *a, t_swap *b)
{
	int		max;

	if (b->stacksize == 0)
		return ;
	max = find_max(b);
	split_to_a(a, b, find_median(b), b->stacksize);
	while ((a->stack[0] == find_next(a, a->stack[a->stacksize - 1]) ||
			a->stack[0] == a->lowest_int) && !check_sort(a))
	{
		if (a->stack[0] == find_min(a) &&
					a->stack[a->stacksize - 1] == find_max(a))
			break ;
		ft_rotate(a, "ra\n");
	}
	quick_sort_algo(a, b);
	if (get_amount(a, max) >= 20)
		back_track_quicksort(a, b, max);
	split_back_to_b(a, b, max);
}

void	hard_algo(t_swap *a, t_swap *b)
{
	if (sorted(a) == 0)
		return ;
	split_to_b(a, b, find_median(a), a->stacksize);
	quick_sort_algo(a, b);
	if (get_amount(a, find_max(a)) >= 20)
	{
		back_track_quicksort(a, b, find_max(a));
		back_track_quicksort(a, b, find_max(a));
	}
	split_back_to_b(a, b, find_max(a));
}
