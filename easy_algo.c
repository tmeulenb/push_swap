/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easy_algo.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/13 14:35:05 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/05/13 14:35:06 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sorted_ascending(t_swap *a)
{
	int		i;

	i = 0;
	while (i < a->stacksize)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (i);
		i++;
	}
	return (-1);
}

void	sort_three(t_swap *a)
{
	long int		a1;
	long int		a2;
	long int		a3;

	a1 = a->stack[0];
	a2 = a->stack[1];
	a3 = a->stack[2];
	if (a1 < a2 && a1 < a3 && a2 > a3)
	{
		ft_rev_rotate(a, "rra\n");
		ft_swap(a, "sa\n");
	}
	else if (a1 > a2 && a1 < a3 && a2 < a3)
		ft_swap(a, "sa\n");
	else if (a1 < a2 && a1 > a3 && a2 > a3)
		ft_rev_rotate(a, "rra\n");
	else if (a1 > a2 && a1 > a3 && a2 < a3)
		ft_rotate(a, "ra\n");
	else if (a1 > a2 && a1 > a3 && a2 > a3)
	{
		ft_rotate(a, "ra\n");
		ft_swap(a, "sa\n");
	}
}

void	get_to_b(t_swap *a, t_swap *b)
{
	int		median;

	median = a->sorted_stack[a->stacksize / 2];
	if (a->stacksize == 5)
	{
		while (a->stacksize > 3)
		{
			if (a->stack[0] < median)
				ft_push(a, b, "pb\n");
			else
				ft_rotate(a, "ra\n");
		}
	}
	if (a->stacksize == 4)
	{
		while (a->stacksize > 2)
		{
			if (a->stack[0] < median)
				ft_push(a, b, "pb\n");
			else
				ft_rotate(a, "ra\n");
		}
	}
	return ;
}

void	easy_algo(t_swap *a, t_swap *b)
{
	get_to_b(a, b);
	if (b->stacksize == 2 && b->stack[0] < b->stack[1])
		ft_swap(b, "sb\n");
	if (a->stacksize == 2 && a->stack[0] > a->stack[1])
		ft_swap(a, "sa\n");
	else
		sort_three(a);
	while (b->stacksize)
		ft_push(b, a, "pa\n");
	return ;
}
