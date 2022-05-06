/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:18:12 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/22 18:42:12 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_show_tab(struct s_stock_str *par);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while ((par[i]).str)
	{
		ft_putstr((par[i]).str);
		ft_putnbr((par[i]).size);
		write(1, "\n", 1);
		ft_putstr((par[i]).copy);
		i++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	nb = (nb % 10) + '0';
	write(1, &nb, 1);
}
