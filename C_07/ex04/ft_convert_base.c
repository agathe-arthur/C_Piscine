/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 02:02:20 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/25 11:21:37 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

char		*ft_convert_base(char *nbr, char *base_from, char *base_to);
long int	ft_atoi_base(char *nbr, char *base, int size);
int			ft_count_digits(long int nb, int size);
int			ft_is_base(char c, char *base);
int			ft_strlen(char *str);
void		ft_fill_nb(long int nb, char *str, char *base_to, long int size);
int			ft_check(char *base, int size);
int			ft_win_lines(char *nbr, int *pos);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			i;
	long int	conv;
	int			pos;
	char		*str;
	int			digits;

	pos = 1;
	if (!(nbr && ft_check(base_from, ft_strlen(base_from))
			&& ft_check(base_to, ft_strlen(base_to))))
		return (NULL);
	i = ft_win_lines(nbr, &pos);
	conv = ft_atoi_base(nbr + i, base_from, ft_strlen(base_from));
	digits = ft_count_digits(conv, ft_strlen(base_to));
	if (pos < 0 && conv != 0)
		digits++;
	str = (char *) malloc((digits + 1) * sizeof(char));
	if (pos < 0 && conv != 0)
		str[0] = '-';
	ft_fill_nb(conv, str + digits - 1, base_to, ft_strlen(base_to));
	str[digits] = '\0';
	return (str);
}

long int	ft_atoi_base(char *nbr, char *base, int size)
{
	int			i;
	int			place;
	long int	result;

	i = 0;
	result = 0;
	place = ft_is_base(nbr[i], base);
	while (place != -1)
	{
		result = (result * size) + place;
		i++;
		place = ft_is_base(nbr[i], base);
	}
	return (result);
}

int	ft_count_digits(long int nb, int size)
{
	int	i;

	i = 1;
	while (nb >= size)
	{
		nb = nb / size;
		i++;
	}
	return (i);
}

int	ft_is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
