/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:06:27 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/23 14:40:28 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);
int		ft_skip_charset(char *str, char *charset);
int		ft_is_charset(char c, char *charset);
int		ft_count_word(char *str, char *charset);
void	ft_win_lines(char **list, int ct_word, char *str, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**list;
	int		i;
	int		ct_word;

	i = ft_skip_charset(str, charset);
	if (!(*(str + i)))
	{
		list = (char **) malloc(sizeof(char *));
		list[0] = NULL;
		return (list);
	}
	ct_word = ft_count_word(str + i, charset);
	list = (char **) malloc((ct_word + 1) * sizeof(char *));
	if (list != NULL)
		ft_win_lines(list, ct_word, str, charset);
	return (list);
}

void	ft_win_lines(char **list, int ct_word, char *str, char *charset)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 0;
	list[ct_word] = NULL;
	while (str[i] && k < ct_word)
	{
		l = 0;
		j = 0;
		i = i + ft_skip_charset(str + i, charset);
		while (str[i + j] && !ft_is_charset(str[i + j], charset))
			j++;
		list[k] = (char *) malloc((j + 1) * sizeof(char));
		list[k][j] = 0;
		while (l < j)
		{
			list[k][l] = str[i + l];
			l++;
		}
		i = i + j;
		k++;
	}
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	ct_word;
	int	is_sep;

	i = 0;
	ct_word = 0;
	is_sep = 0;
	while (str[i])
	{
		if (ft_is_charset(str[i], charset))
		{
			if (is_sep == 0)
				ct_word++;
			is_sep = 1;
		}
		else
			is_sep = 0;
		i++;
	}
	if (is_sep == 0)
		ct_word++;
	return (ct_word);
}

int	ft_skip_charset(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (charset[j] && str[i])
	{
		if (str[i] == charset[j])
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (i);
}			

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}
