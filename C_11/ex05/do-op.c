/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:48:56 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/24 14:37:29 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check_op(char *str);
int		ft_is_zero(char *str);
void	ft_calcul(char *argv[]);
int		ft_sum(int val1, int val2);
int		ft_subst(int val1, int val2);
int		ft_mult(int val1, int val2);
int		ft_div(int val1, int val2);
int		ft_mod(int val1, int val2);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);

int	main(int argc, char *argv[])
{
	if (!(argc != 4))
	{
		if (!ft_check_op(argv[2]))
			write(1, "0\n", 2);
		else
		{
			if (*argv[2] == '/' && ft_is_zero(argv[3]))
				write(2, "Stop : division by zero\n", 24);
			else if (*argv[2] == '%' && ft_is_zero(argv[3]))
				write(2, "Stop : modulo by zero\n", 22);
			else
			{
				ft_calcul(argv);
			}
		}
	}
	return (0);
}

int	ft_check_op(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 1 || (*str != '+' && *str != '-' && *str != '/'
			&& *str != '*' && *str != '%'))
		return (0);
	return (1);
}

int	ft_is_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i == 1 && *str == '0')
		return (1);
	return (0);
}

void	ft_calcul(char *argv[])
{
	int	val1;
	int	val2;
	int	result;
	int	(*f)(int, int);

	result = 0;
	val1 = ft_atoi(argv[1]);
	val2 = ft_atoi(argv[3]);
	if (argv[2][0] == '+')
		f = &ft_sum;
	else if (argv[2][0] == '-')
		f = &ft_subst;
	else if (argv[2][0] == '*')
		f = &ft_mult;
	else if (argv[2][0] == '/')
		f = &ft_div;
	else
		f = &ft_mod;
	result = (*f)(val1, val2);
	ft_putnbr(result);
	write(1, "\n", 1);
}
