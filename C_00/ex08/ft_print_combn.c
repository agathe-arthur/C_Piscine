/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:03:30 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/11 11:29:09 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	ft_recurs(char *array_char, int n, int const t);
void	ft_init_array(char *array_char, int l, int n);
void	ft_array_reset(char *array_char, int n);
void	ft_print_array(char *array_char, int n);

void	ft_print_combn(int n)
{
	char	array_char[9];

	if (n > 0 && n < 10)
	{
		ft_init_array(array_char, 9, n);
		ft_recurs(array_char, n, n);
	}
	else
		write(1, "Mauvais nombre", 14);
}

void	ft_recurs(char *array_char, int n, int const t)
{
	while (array_char[n - 1] <= '9' - n + 1)
	{
		if (n != 1)
		{
			ft_recurs(array_char, n - 1, t);
		}
		else
			ft_print_array(array_char, t);
		ft_array_reset(array_char, n);
	}
}

void	ft_init_array(char *array_char, int l, int n)
{
	int		i;

	i = 0;
	while (i < l)
	{
		array_char[i] = n - 1 - i + '0';
		i++;
	}
}

void	ft_array_reset(char *array_char, int n)
{
	int		i;

	i = n;
	array_char[i - 1] = array_char[i - 1] + 1;
	while (i > 0)
	{
		i--;
		array_char[i - 1] = array_char[n - 1] + n - i;
	}
}

void	ft_print_array(char *array_char, int const t)
{
	int		i;

	i = 0;
	while (i < t)
	{
		write(1, &array_char[t - 1 - i], 1);
		i++;
	}
	if (array_char[t - 1] != '9' - t + 1)
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}
