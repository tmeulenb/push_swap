/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:33:19 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:33:20 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static char	*ft_copy_pasta(const char *s, char c, int i)
{
	char	*str;
	int		x;

	x = 0;
	if (!(str = (char *)malloc(sizeof(str) * (ft_strlen(s)))))
		return (NULL);
	while (s[i] != c && s[i])
	{
		str[x] = s[i];
		x++;
		i = i + 1;
	}
	str[x] = '\0';
	while (s[i] == c && s[i])
		i = i + 1;
	return (str);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		x;
	char	**str;

	i = 0;
	x = 0;
	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(str) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (x < ft_count_words(s, c) && s[i])
	{
		str[x] = ft_copy_pasta(s, c, i);
		x++;
	}
	str[x] = NULL;
	return (str);
}
