/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 15:23:34 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/05/16 15:23:50 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_swap *p, char *cmd)
{
	int		swap;

	if (p->stacksize <= 1)
		return ;
	swap = p->stack[0];
	p->stack[0] = p->stack[1];
	p->stack[1] = swap;
	p->swaps++;
	if (p->push_swap == 1)
		ft_putstr(cmd);
}

void	ft_push(t_swap *from, t_swap *to, char *cmd)
{
	if (from->stacksize >= 1)
	{
		to->stacksize++;
		add_top(to);
		to->stack[0] = from->stack[0];
		remove_top(from);
		from->stacksize--;
	}
	from->pushes++;
	if (from->push_swap == 1)
		ft_putstr(cmd);
}

void	ft_rotate(t_swap *p, char *cmd)
{
	int		swap;
	int		begin;
	int		i;

	if (p->stacksize > 1)
	{
		i = 0;
		begin = p->stack[0];
		while (i < p->stacksize)
		{
			swap = p->stack[i];
			p->stack[i] = p->stack[i + 1];
			p->stack[i + 1] = swap;
			i++;
		}
		p->stack[p->stacksize - 1] = begin;
	}
	p->rotates++;
	if (p->push_swap == 1)
		ft_putstr(cmd);
}

void	ft_rev_rotate(t_swap *p, char *cmd)
{
	int		last;
	int		i;

	if (p->stacksize > 1)
	{
		i = p->stacksize - 1;
		last = p->stack[i];
		while (i - 1 >= 0)
		{
			p->stack[i] = p->stack[i - 1];
			i--;
		}
		p->stack[0] = last;
	}
	p->rev_rotates++;
	if (p->push_swap == 1)
		ft_putstr(cmd);
}
