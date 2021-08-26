/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:42:53 by strisha           #+#    #+#             */
/*   Updated: 2021/08/10 17:06:32 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	output(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i <= 9)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	c = '\n';
	write(1, &c, 1);
}

int	check_diag(int a, int b)
{
	if (a >= b)
		return (a - b);
	else
		return (b - a);
}

int	safe(int cur, int *board)
{
	int	i;

	i = 0;
	while (i < cur)
	{
		if ((board[i] == board[cur]) || \
				(check_diag(board[cur], board[i]) == (cur - i)))
			return (0);
		i++;
	}
	return (1);
}

void	search(int cur, int *board, int *count)
{
	board[cur] = 0;
	while (board[cur] < 10)
	{
		if (safe(cur, board))
		{
			if (cur == 9)
			{
				output(board);
				*count = *count + 1;
			}
			else
				search(cur + 1, board, count);
		}
		board[cur]++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	count;
	int	board[10];
	int	cur;

	cur = 0;
	count = 0;
	search(cur, board, &count);
	return (count);
}
