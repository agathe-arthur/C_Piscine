/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:51:54 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/21 23:11:48 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);
void	ft_cat_str(char *str, char *src, char *sep, int nul);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		ct_letter;
	int		i;

	i = -1;
	ct_letter = 0;
	while (++i < size)
		ct_letter += ft_strlen(strs[i]);
	ct_letter += ft_strlen(sep) * (i - 1);
	if (ct_letter < 0)
		ct_letter = 0;
	str = (char *) malloc((ct_letter + 1) * sizeof(char));
	if (str != NULL)
	{
		str[0] = '\0';
		i = -1;
		while (++i < size)
			ft_cat_str(str, strs[i], sep, size - i - 1);
	}
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_cat_str(char *str, char *src, char *sep, int nul)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (str[i])
		i++;
	j = 0;
	while (src[j])
	{
		str[i + j] = src[j];
		j++;
	}
	k = 0;
	if (nul)
	{
		while (sep[k])
		{
			str[i + j + k] = sep[k];
			k++;
		}
	}
	str[i + j + k] = '\0';
}
