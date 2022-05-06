/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 03:05:40 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/25 20:02:59 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_fill_nb(long int nb, char *str, char *base_to, long int size);
int		ft_check(char *base, int size);
int		ft_win_lines(char *nbr, int *pos);

void	ft_fill_nb(long int nb, char *str, char *base_to, long int size)
{
	if (nb >= size)
		ft_fill_nb(nb / size, str - 1, base_to, size);
	*str = base_to[nb % size];
}

int	ft_check(char *base, int size)
{
	int	i;
	int	j;

	i = 0;
	if (size < 2)
		return (0);
	while (base[i + 1])
	{
		j = i;
		while (base[++j])
		{
			if (base[i] == base[j])
				return (0);
		}
		i++;
	}
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_win_lines(char *nbr, int *pos)
{
	int	i;

	i = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			*pos = *pos * (-1);
		i++;
	}
	return (i);
}
