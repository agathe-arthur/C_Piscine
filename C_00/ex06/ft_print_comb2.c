/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:51:14 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/10 10:48:20 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	ft_print_nb(char a, char b, char c, char d);
void	init_char(char *a, char *b, char *c, char *d);
void	reset_a(char *a, char *b, char *c, char *d);
void	reset_b(char a, char *b, char *c, char *d);

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	init_char(&a, &b, &c, &d);
	while (a <= '9')
	{
		while (b <= '9')
		{
			while (c <= '9')
			{
				while (d <= '9')
				{
					ft_print_nb(a, b, c, d);
					d++;
				}
				c++;
				d = '0';
			}
			reset_b(a, &b, &c, &d);
		}
		reset_a(&a, &b, &c, &d);
	}
}

void	ft_print_nb(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (a != '9' || b != '8')
		write(1, ", ", 2);
}

void	init_char(char *a, char *b, char *c, char *d)
{
	*a = '0';
	*b = '0';
	*c = '0';
	*d = '1';
}

void	reset_a(char *a, char *b, char *c, char *d)
{
	*a = *a + 1;
	*b = '0';
	*c = *a;
	*d = *b + 1;
}

void	reset_b(char a, char *b, char *c, char *d)
{
	*b = *b + 1;
	*d = *b + 1;
	*c = a;
}
