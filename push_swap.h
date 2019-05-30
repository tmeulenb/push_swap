/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/23 19:55:23 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/04/23 19:55:25 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_swap
{
	int				argc;
	char			**argv;
	int				*stack;
	int				stacksize;
	int				push_swap;
	int				checker;
	int				lowest_int;
	int				*sorted_stack;
	int				size;
	int				visualize_sorting;
	int				display_stack;
	int				display_amount_of_commands;
	int				display_amount_of_commands_per_command;
	int				push_swap_is_checker;
	int				help_display;
	int				amount_of_flags;
	int				swaps;
	int				pushes;
	int				rotates;
	int				rev_rotates;
}					t_swap;

# define MAX_INT 2147483647
# define MIN_INT -2147483648

/*
** Initializing
*/
void				initialize_struct(t_swap *ps, int argc, char **argv);
void				initialize_variables(t_swap *a, t_swap *b);
void				make_stacks(t_swap *a);
t_swap				*pw_newlist(void);

/*
** Extra-functions
*/
void				show_stacks(t_swap *a, t_swap *b);
void				help_display(void);

/*
** Inputcheck && Flagcheck
*/
void				error(int choice);
void				check_string_for_non_numeric(char *str);
void				check_value(long long nbr);
void				check_reoccurence(t_swap *a, int reocurring);
void				exec_flags(t_swap *a, t_swap *b);
int					check_flags(t_swap *a, int pos);

/*
** Algorithms
*/
void				sort_three(t_swap *a);
void				easy_algo(t_swap *a, t_swap *b);
void				hard_algo(t_swap *a, t_swap *b);

/*
** Functions that check sorting
*/
int					sorted(t_swap *a);
int					check_sorted_ascending(t_swap *a);

/*
**Operations && operation_help
*/
void				ft_swap(t_swap *p, char *cmd);
void				ft_push(t_swap *from, t_swap *to, char *cmd);
void				ft_rotate(t_swap *p, char *cmd);
void				ft_rev_rotate(t_swap *p, char *cmd);
void				add_top(t_swap *to);
void				remove_top(t_swap *from);
void				do_operations_for_both(t_swap *b, t_swap *a, int choice);
void				check_valid_operation(t_swap *b, t_swap *a, char *str);

/*
** sort_A.c
*/
int					check_sort(t_swap *s);
void				get_median_to_a(t_swap *a, t_swap *b);
void				split_to_a(t_swap *a, t_swap *b, int median, int stacksize);
void				quick_sort_algo(t_swap *a, t_swap *b);

/*
** sort_b.c
*/
void				split_to_b(t_swap *a, t_swap *b, int median, int stacksize);
void				split_back_to_b(t_swap *a, t_swap *b, int max);
void				back_track_quicksort(t_swap *a, t_swap *b, int max);

/*
** sort_help.c
*/

int					find_max(t_swap *s);
int					find_min(t_swap *s);
int					find_next(t_swap *s, int current);
int					find_pos(t_swap *s, int to_find);
void				smart_rotate(t_swap *s, int pos, char c);
int					find_median(t_swap *s);
int					find_median_using_limit(t_swap *s, int limit);
int					get_amount(t_swap *s, int median);
int					*sort_stack(int *tab, int size);
void				make_sorted_stack(t_swap *a);
#endif
