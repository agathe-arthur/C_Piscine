/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:29:25 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/25 19:58:45 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	ft_init(long int *l_min, long int *l_max, int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	long int	size;
	long int	l_min;
	long int	l_max;
	int			i;

	i = 0;
	ft_init(&l_min, &l_max, min, max);
	size = l_max - l_min;
	if (size <= 0)
	{
		range = NULL;
		return (0);
	}
	*range = (int *) malloc(size * sizeof(int));
	if (*range != NULL)
	{
		while (l_min < l_max)
		{
			(*range)[i] = l_min;
			l_min++;
			i++;
		}
		return (i);
	}
	return (-1);
}

void	ft_init(long int *l_min, long int *l_max, int min, int max)
{
	*l_max = max;
	*l_min = min;
}
