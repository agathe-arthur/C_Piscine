/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:29:21 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/29 12:56:51 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	val;
	int	comp;

	i = 0;
	val = 0;
	comp = 0;
	if (length < 3)
		return (1);
	while (i < length - 1 && !val)
	{
		val = (*f)(tab[i], tab[i + 1]);
		i++;
	}
	while (i < length - 1)
	{
		comp = (*f)(tab[i], tab[i + 1]);
		if (comp < 0 && val > 0)
			return (0);
		if (comp > 0 && val < 0)
			return (0);
		i++;
	}
	return (1);
}
