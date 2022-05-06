/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:20:15 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/16 12:27:09 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base);
int	ft_mult(int nb, int pui);
int	ft_count_nb(char *str, char *base, int size);
int	ft_nbr_base(char *str, char *base, int count, int size);
int	ft_check(char *base, int size);

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	pos;
	int	result;
	int	size;

	size = 0;
	while (base && base[size] != '\0')
		size++;
	pos = -1;
	if (!ft_check(base, size))
		return (0);
	i = 0;
	while (str && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	while (str && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			pos = pos * (-1);
		i++;
	}
	if (!(ft_count_nb(str + i, base, size)))
		return (0);
	result = ft_nbr_base(str + i, base, ft_count_nb(str + i, base, size), size);
	return (result * pos);
}

int	ft_nbr_base(char *str, char *base, int count, int size)
{
	int	i;
	int	j;
	int	result;

	result = 0;
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < size)
		{
			if (str[i] == base[j])
				result = result - (j * ft_mult(size, count - 1 - i));
			j++;
		}
		i++;
	}
	return (result);
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

int	ft_count_nb(char *str, char *base, int size)
{
	int	i;
	int	j;
	int	check;

	j = 0;
	while (str && str[j] != '\0')
	{
		check = j;
		i = 0;
		while (i < size && j == check)
		{
			if (base[i] == str[j])
				j++;
			else
				i++;
		}
		if (check == j)
			return (j);
	}
	return (j);
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
