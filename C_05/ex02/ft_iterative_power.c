/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:26:20 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/20 23:40:50 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power);

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	i = 0;
	if (power < 0)
		return (0);
	result = 1;
	while (i < power)
	{
		result = result * nb;
		i++;
	}
	return (result);
}
