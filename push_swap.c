/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap3.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 20:24:27 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/05/23 20:24:27 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_pw(t_swap *s)
{
	free(s->sorted_stack);
	free(s->stack);
	free(s);
}

void	choose_algo(t_swap *a, t_swap *b)
{
	if (a->stacksize > 1 && a->stacksize <= 5)
		easy_algo(a, b);
	else if (a->stacksize > 5)
		hard_algo(a, b);
}

int		main(int argc, char **argv)
{
	t_swap *a;
	t_swap *b;

	a = pw_newlist();
	b = pw_newlist();
	if (argc >= 2)
	{
		initialize_struct(a, argc, argv);
		initialize_struct(b, argc, argv);
		make_stacks(a);
		if (a->stacksize == 0)
			error(2);
		make_sorted_stack(a);
		initialize_variables(a, b);
		choose_algo(a, b);
		free_stack_pw(a);
		free_stack_pw(b);
	}
	else
		ft_putstr("Usage: ./push_swap -flags 'integers'\n");
	return (0);
}
