/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_help1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/30 15:06:48 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/05/30 15:06:49 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_next(t_swap *s, int current)
{
	int		i;

	i = 0;
	while (i < s->size)
	{
		if (s->sorted_stack[i] == current)
			return (s->sorted_stack[i + 1]);
		i++;
	}
	return (MIN_INT);
}
