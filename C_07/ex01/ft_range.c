/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:29:25 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/25 20:02:14 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long int	range;
	int			*tab;
	int			i;
	long int	l_min;
	long int	l_max;

	i = 0;
	l_min = min;
	l_max = max;
	range = l_max - l_min;
	if (range <= 0)
		return (NULL);
	tab = (int *) malloc(range * sizeof(int));
	if (tab != NULL)
	{
		while (l_min < l_max)
		{
			tab[i] = l_min;
			l_min++;
			i++;
		}
	}
	return (tab);
}
