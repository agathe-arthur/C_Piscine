/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:11:52 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/22 14:48:14 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_ten_queens_puzzle(void);
void	ft_init_board(char *board);
void	ft_recurs(char *board, int pos, int *count);
int		ft_find_pos(char *board, int pos, char place);
void	ft_print_board(char *board);
void	main()
{
	ft_ten_queens_puzzle();

}
int	ft_ten_queens_puzzle(void)
{
	char	board[11];
	int		count;

	count = 0;
	ft_init_board(board);
	ft_recurs(board, 0, &count);
	return (count);
}

void	ft_init_board(char *board)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		board[i] = '0';
		i++;
	}
	board[i] = '\0';
}

void	ft_recurs(char *board, int pos, int *count)
{
	char	place;
	int		find;

	place = '0';
	while (place <= '9')
	{
		find = ft_find_pos(board, pos, place);
		if (find && pos != 9)
			ft_recurs(board, pos + 1, count);
		else if (find && pos == 9)
		{
			ft_print_board(board);
			*count = *count + 1;
		}
		place++;
	}
}

int	ft_find_pos(char *board, int pos, char place)
{
	int	i;
	int	diffl;
	int	diffv;

	i = 0;
	while (i < pos)
	{
		diffl = pos - i;
		diffv = place - board[i];
		if (board[i] == place)
			return (0);
		if (diffl - diffv == 0 || diffl + diffv == 0)
			return (0);
		i++;
	}
	board[pos] = place;
	return (1);
}

void	ft_print_board(char *board)
{
	int		i;

	i = 0;
	while (board[i])
	{
		write(1, &board[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
