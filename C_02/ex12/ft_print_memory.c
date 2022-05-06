/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:34:49 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/16 13:17:13 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_hexa(long long val, char *str, int i, int n);
void	ft_put_hexa_a(long long address, char *str);
void	ft_put_hexa_v(char val, int j, char *str, int end);
void	ft_print_v(char *str, int n, int j, int end);
void	*ft_print_memory(void *addr, unsigned int size);

void	ft_put_hexa(long long val, char *str, int i, int n)
{
	long long	a;

	a = val;
	if (a > 15)
		ft_put_hexa(a / 16, str, i - 1, 0);
	val = val % 16;
	if (val < 10)
		val = val + '0';
	else
		val = val + 'W';
	str[i] = val;
	if (n == 1)
		str[i - 1] = '0';
}

void	ft_put_hexa_a(long long address, char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = '0';
		i++;
	}
	i = 15;
	ft_put_hexa(address, str, i, 0);
	i = 0;
	while (str && !(str[i] >= '0' && str[i] <= '9'))
	{
			str[i] = '0';
			i++;
	}
	i = 0;
	while (str && str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, ": ", 2);
}

void	ft_put_hexa_v(char val, int j, char *str, int end)
{
	static char	str2[33];
	int			k;
	int			i;

	str2[32] = 0;
	if (j == 0)
	{	
		i = 0;
		while (str2[i] != '\0')
		{
			str2[i] = '0';
			i++;
		}
	}
	k = j * 2 + 1;
	if (val < 16)
		ft_put_hexa(val, str2, k, 1);
	else
		ft_put_hexa(val, str2, k, 0);
	if (j == 15 || end == 1)
		ft_print_v(str2, 1, 16, end);
	if (val >= 32 && val < 127)
		str[j] = val;
	else
		str[j] = '.';
}

void	ft_print_v(char *str, int n, int j, int end)
{
	int		i;
	int		ct;

	i = 0;
	ct = 0;
	while (str && str[i] != '\0' && !(ct >= 2 && str[i] == '0' && i % 2 == 0))
	{
		if (j == 16 || i < j)
			write(1, &str[i], 1);
		i++;
		if ((i % 4) == 0 && n == 1)
			write(1, " ", 1);
		if (n == 0 && str[i] == '\0')
			write(1, "\n", 1);
		if (str[i - 1] == '0')
			ct++;
		else
			ct = 0;
	}
	if (end == 1 && (ct >= 2 && str[i] == '0' && i % 2 == 0))
		write(1, "    ", 4);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	char			*point;
	char			str[17];

	point = addr;
	str[16] = 0;
	i = 0;
	while (addr && i < size)
	{
		j = 0;
		ft_put_hexa_a((long long)(addr + i), str);
		while (j < 16 && i < size)
		{
			if (i + 1 == size)
				ft_put_hexa_v('\0', j, str, 1);
			else
				ft_put_hexa_v(point[i], j, str, 0);
			i++;
			j++;
		}
		ft_print_v(str, 0, j, 0);
	}
	return (addr);
}
