/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 15:30:23 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/01/21 15:30:24 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_listcheck(t_list **list, int fd)
{
	t_list	*newlist;

	if (!list)
		return (NULL);
	newlist = *list;
	while (newlist)
	{
		if ((int)newlist->content_size == fd)
			return (newlist);
		newlist = newlist->next;
	}
	newlist = ft_lstnew("", fd);
	ft_lstadd(list, newlist);
	return (newlist);
}

static int		ft_copy_into_line(char **line, char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(*line = ft_strndup(str, i)))
		return (0);
	return (i);
}

static int		ft_read(char **line, int fd)
{
	size_t			ret;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = *line;
		MALLOCCHECK((*line = ft_strjoin(*line, buf)));
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	size_t				ret;
	t_list				*current;
	static t_list		*list;
	char				*tmp;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0)
					|| (!(current = ft_listcheck(&list, fd))))
		return (-1);
	tmp = current->content;
	ret = ft_read(&tmp, fd);
	current->content = tmp;
	if (!ret && !*tmp)
		return (0);
	ret = ft_copy_into_line(line, current->content, '\n');
	tmp = current->content;
	if (tmp[ret] != '\0')
	{
		current->content = ft_strdup(&((current->content[ret + 1])));
		free(tmp);
	}
	else
		tmp[0] = '\0';
	return (1);
}
