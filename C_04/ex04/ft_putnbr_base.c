/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:18:15 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/16 10:36:35 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
int		ft_strlen(char *str);
int		ft_check(char *base, int size);

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	size = ft_strlen(base);
	if (!ft_check(base, size))
		return ;
	if (nbr >= size || nbr <= -size)
		ft_putnbr_base(nbr / size, base);
	if (nbr > -size && nbr < 0)
		write(1, "-", 1);
	if (nbr >= 0 || nbr % size == 0)
		nbr = base[nbr % size];
	else
		nbr = base[-(nbr % size)];
	write(1, &nbr, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int	ft_check(char *base, int size)
{
	int	i;
	int	j;

	if (!(*base && *(base + 1)))
		return (0);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}
