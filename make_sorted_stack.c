/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_sorted_stack.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/30 15:32:39 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/05/30 15:32:39 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*sort_stack(int *tab, int size)
{
	int		i;
	int		swap;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

void	make_sorted_stack(t_swap *a)
{
	int		i;

	i = 0;
	while (i < a->stacksize)
	{
		a->sorted_stack[i] = a->stack[i];
		i++;
	}
	a->sorted_stack = sort_stack(a->sorted_stack, a->stacksize);
	a->sorted_stack = a->sorted_stack;
	a->size = a->stacksize;
	return ;
}
