/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 19:53:15 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/04/25 19:53:16 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		smart_rotate(t_swap *s, int pos, char c)
{
	if (pos <= (s->stacksize / 2))
	{
		if (c == 'a')
			ft_rotate(s, "ra\n");
		else if (c == 'b')
			ft_rotate(s, "rb\n");
	}
	else if (pos > (s->stacksize / 2))
	{
		if (c == 'a')
			ft_rev_rotate(s, "rra\n");
		else if (c == 'b')
			ft_rev_rotate(s, "rrb\n");
	}
	return ;
}

void		add_top(t_swap *to)
{
	int		i;
	int		len;

	len = to->stacksize;
	i = 0;
	if (len > 1)
	{
		while (len)
		{
			to->stack[len] = to->stack[len - 1];
			len--;
		}
	}
}

void		remove_top(t_swap *from)
{
	int		i;
	int		len;

	len = from->stacksize;
	i = 0;
	while (i < len)
	{
		from->stack[i] = from->stack[i + 1];
		i++;
	}
}

void		do_operations_for_both(t_swap *a, t_swap *b, int choice)
{
	if (choice == 1)
	{
		ft_swap(a, "s");
		ft_swap(b, "s\n");
	}
	else if (choice == 2)
	{
		ft_rotate(a, "r");
		ft_rotate(b, "r\n");
	}
	else if (choice == 3)
	{
		ft_rev_rotate(a, "rr");
		ft_rev_rotate(b, "r\n");
	}
	return ;
}

void		check_valid_operation(t_swap *a, t_swap *b, char *str)
{
	if (ft_strnequ(str, "sa", 3))
		ft_swap(a, "sa\n");
	else if (ft_strnequ(str, "sb", 3))
		ft_swap(b, "sb\n");
	else if (ft_strnequ(str, "ss", 3))
		do_operations_for_both(a, b, 1);
	else if (ft_strnequ(str, "pb", 3))
		ft_push(a, b, "pb\n");
	else if (ft_strnequ(str, "pa", 3))
		ft_push(b, a, "pa\n");
	else if (ft_strnequ(str, "ra", 3))
		ft_rotate(a, "ra\n");
	else if (ft_strnequ(str, "rb", 3))
		ft_rotate(b, "rb\n");
	else if (ft_strnequ(str, "rr", 3))
		do_operations_for_both(a, b, 2);
	else if (ft_strnequ(str, "rra", 4))
		ft_rev_rotate(a, "rra\n");
	else if (ft_strnequ(str, "rrb", 4))
		ft_rev_rotate(b, "rrb\n");
	else if (ft_strnequ(str, "rrr", 4))
		do_operations_for_both(a, b, 3);
	else
		error(0);
}
