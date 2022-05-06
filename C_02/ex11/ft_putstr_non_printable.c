/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:30:30 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/15 12:48:02 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);
void	ft_put_hexa(unsigned char c);

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, "\\", 1);
			if (str[i] > 0 && str[i] < 16)
				write(1, "0", 1);
			ft_put_hexa(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	ft_put_hexa(unsigned char c)
{
	unsigned char	a;

	a = c;
	if (c > 15)
	{
		a = c / 16;
		ft_put_hexa(a);
		c = c % 16;
	}
	if (c < 10)
		c = c + '0';
	else
		c = c + 'W';
	write(1, &c, 1);
}	
