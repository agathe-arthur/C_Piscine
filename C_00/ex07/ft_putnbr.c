/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:15:00 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/11 13:20:06 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_pos_numb(int *nb, int *spe);
void	ft_put_array(char *array_int, int j);
int		ft_mult(int a, int b);

void	ft_putnbr(int nb)
{
	char	array_int[11];
	int		i;
	int		j;
	int		spe;

	spe = 0;
	if (nb < 0)
		ft_pos_numb(&nb, &spe);
	i = 9;
	j = 0;
	while (i >= 0)
	{
		if (i < 9)
			array_int[i] = (nb % (10 * ft_mult(10, i)) / ft_mult(10, i));
		else
			array_int[i] = nb / ft_mult(10, i);
		if (array_int[i] != 0 && j == 0)
			j = i;
		array_int[i] = array_int[i] + '0';
		i--;
	}
	if (spe == 1)
		array_int[0]++;
	ft_put_array(array_int, j);
}

void	ft_put_array(char *array_int, int j)
{
	while (j >= 0)
	{
		ft_putchar(array_int[j]);
		j--;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_mult(int a, int b)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < b)
	{
		result = result * a;
		i++;
	}
	return (result);
}

void	ft_pos_numb(int *nb, int *spe)
{
	ft_putchar('-');
	if (*nb == -2147483648)
	{
		*nb = *nb + 1;
		*spe = 1;
	}
		*nb = *nb * (-1);
}
