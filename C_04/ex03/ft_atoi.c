/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:20:15 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/16 10:49:44 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);
int	ft_mult(int nb, int pui);
int	ft_space_sign(char *str, int *pos);

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	k;
	int	pos;
	int	result;

	i = 0;
	j = 0;
	k = 0;
	result = 0;
	pos = -1;
	i = ft_space_sign(str, &pos);
	while (str && str[i + j] >= '0' && str[i + j] <= '9')
		j++;
	if (j == 0)
		return (0);
	while (k < j)
	{
		result = result - ((str[i + k] - '0') * ft_mult(10, j - k - 1));
		k++;
	}
	return (result * pos);
}

int	ft_mult(int nb, int pui)
{
	int	i;
	int	mult;

	i = 0;
	mult = 1;
	while (i < pui)
	{
		mult = mult * nb;
		i++;
	}
	return (mult);
}

int	ft_space_sign(char *str, int *pos)
{
	int	i;

	i = 0;
	while (str && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	while (str && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			*pos = *pos * (-1);
		i++;
	}
	return (i);
}
