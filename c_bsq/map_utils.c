/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:29:38 by strisha           #+#    #+#             */
/*   Updated: 2021/08/24 17:51:29 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, t_ui n)
{
	write(1, str, n);
}

void	display_map(char **map, t_map params)
{
	t_ui	i;

	i = 0;
	while (i < params.n)
	{
		ft_putstr(map[i], params.m);
		ft_putchar('\n');
		i++;
	}
}

void	fill_square(char **map, t_map params, t_square *square)
{
	t_ui	i;
	t_ui	j;

	if (square->value == 0)
		return ;
	i = square->i - square->value + 1;
	while (i <= square->i)
	{
		j = square->j - square->value + 1;
		while (j <= square->j)
		{
			map[i][j] = params.full_ch;
			j++;
		}
		i++;
	}
}

t_map	map_init(t_ui n, t_ui m, char set[4])
{
	t_map	map;

	map.n = n;
	map.m = m;
	map.empty_ch = set[0];
	map.obstacle_ch = set[1];
	map.full_ch = set[2];
	return (map);
}
