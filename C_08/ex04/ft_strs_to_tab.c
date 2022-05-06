/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:50:21 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/22 18:49:33 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void				ft_strcopy(char *copy, char *str);
int					ft_strlen(char *str);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*list;

	i = 0;
	list = (t_stock_str *) malloc((ac + 1) * sizeof(t_stock_str));
	if (list != NULL)
	{
		while (i < ac)
		{
			(list[i]).size = ft_strlen(av[i]);
			(list[i]).str = av[i];
			(list[i]).copy = malloc(((list[i]).size + 1) * sizeof(char));
			ft_strcopy((list[i]).copy, (list[i]).str);
			i++;
		}
		(list[i]).str = 0;
		(list[i]).copy = 0;
		(list[i]).size = 0;
	}
	return (list);
}

void	ft_strcopy(char *copy, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
