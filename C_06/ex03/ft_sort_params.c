/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:14:17 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/18 11:24:56 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **str1, char **str2);
int		ft_compare(char *str1, char *str2);
void	ft_putstr(char *str);

int	main(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			ft_swap(argv + i, argv + j);
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(*(argv + i));
		i++;
	}
	return (0);
}

void	ft_swap(char **str1, char **str2)
{
	char	*str_temp;

	if (ft_compare(*str1, *str2))
	{
		str_temp = *str1;
		*str1 = *str2;
		*str2 = str_temp;
	}
}

int	ft_compare(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] > str2[i])
			return (1);
		if (str1[i] < str2[i])
			return (0);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
