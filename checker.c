/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 17:54:39 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/05/27 17:54:39 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

void	free_stack_ch(t_swap *s)
{
	free(s->stack);
	free(s);
}

void	read_commands(t_swap *a, t_swap *b)
{
	char	*line;

	line = NULL;
	if (a->display_stack)
		show_stacks(a, b);
	while (get_next_line(0, &line))
	{
		check_valid_operation(a, b, line);
		if (a->display_stack)
			show_stacks(a, b);
		if (a->visualize_sorting)
		{
			show_stacks(a, b);
			usleep(300000);
		}
		free(line);
	}
	if (sorted(a) == 0 && b->stacksize == 0)
	{
		write(1, "OK\n", 3);
		return ;
	}
	else
		write(1, "KO\n", 3);
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
		a->checker = 1;
		b->checker = 1;
		make_stacks(a);
		if (a->stacksize == 0)
			error(2);
		read_commands(a, b);
		exec_flags(a, b);
		free_stack_ch(a);
		free_stack_ch(b);
	}
	else
		ft_putstr("Usage: ./checker -flags 'integers'\n");
	return (0);
}
