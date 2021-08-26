/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:07:49 by strisha           #+#    #+#             */
/*   Updated: 2021/08/23 18:40:22 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_ui	**init_cache_matrix(t_ui row, t_ui column, t_ui *j)
{
	t_ui	**cache;
	t_ui	i;

	i = 0;
	cache = (t_ui **)malloc(sizeof(t_ui *) * row);
	while (i < row)
	{
		cache[i++] = (t_ui *)malloc(sizeof(t_ui) * column);
	}
	*j = 0;
	return (cache);
}

void	free_cache_matrix(t_ui **cache, t_ui row)
{
	t_ui	i;

	i = 0;
	while (i < row)
		free(cache[i++]);
	free(cache);
}

t_ui	convert_val(t_map map_params, char c)
{
	if (c == map_params.empty_ch)
		return (1);
	else
		return (0);
}

t_ui	find_min_value(t_ui **cache, t_ui i, t_ui j)
{
	t_ui	min;

	min = cache[i - 1][j];
	if (min > cache[i][j - 1])
		min = cache[i][j - 1];
	if (min > cache[i - 1][j - 1])
		min = cache[i - 1][j - 1];
	return (min);
}

t_square	*init_max_square(void)
{
	t_square	*res;

	res = (t_square *)malloc(sizeof(t_square));
	res->value = 0;
	res->i = 0;
	res->j = 0;
	return (res);
}
