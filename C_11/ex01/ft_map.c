/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:06:45 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/25 12:40:48 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*rval;

	i = 0;
	rval = (int *) malloc(length * sizeof(int));
	if (rval != NULL)
	{
		while (i < length)
		{
			rval[i] = (*f)(tab[i]);
			i++;
		}
	}
	return (rval);
}
