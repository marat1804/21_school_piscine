/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:59:28 by strisha           #+#    #+#             */
/*   Updated: 2021/08/23 19:59:29 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_matrix(char **words)
{
	int	i;

	i = 0;
	while (words[i] != NULL)
		free(words[i++]);
	free(words);
}

void	init_flag_and_i(int	*flag, int *i)
{
	*flag = 1;
	*i = 0;
}

void	free_map(t_map map)
{
	t_ui	i;

	i = 0;
	while (i < map.n)
		free(map.map[i++]);
}

int	cycle_func(char *str, int i, t_map *map_params)
{
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] == '\n')
				return (0);
			++(map_params->m);
		}
		if (!check_in_set(str[i], map_params) && str[i] != '\n')
			return (0);
		++i;
	}
	return (1);
}
