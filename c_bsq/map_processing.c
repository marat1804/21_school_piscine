/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:21:18 by strisha           #+#    #+#             */
/*   Updated: 2021/08/24 17:50:54 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	check_max_value(t_ui val, t_ui i, t_ui j, t_square *max_square)
{
	if (val > max_square->value)
	{
		max_square->value = val;
		max_square->i = i;
		max_square->j = j;
	}
}

void	map_processing(char **map, t_map map_params, t_square *max_square)
{
	t_ui	**cache;
	t_ui	i;
	t_ui	j;

	cache = init_cache_matrix(map_params.n, map_params.m, &i);
	while (i < map_params.n)
	{
		j = 0;
		while (j < map_params.m)
		{
			if (i == 0 || j == 0)
				cache[i][j] = convert_val(map_params, map[i][j]);
			else
			{
				if (map[i][j] == map_params.empty_ch)
					cache[i][j] = 1 + find_min_value(cache, i, j);
				else
					cache[i][j] = 0;
			}
			check_max_value(cache[i][j], i, j, max_square);
			j++;
		}
		i++;
	}
	free_cache_matrix(cache, map_params.n);
}

void	map_find_and_display(char **map, t_map map_params)
{
	t_square	*square;

	square = init_max_square();
	map_processing(map, map_params, square);
	fill_square(map, map_params, square);
	display_map(map, map_params);
	free(square);
}
