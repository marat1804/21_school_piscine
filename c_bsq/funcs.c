/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:14:06 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/25 17:26:25 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	check_in_set(char c, t_map *map_params)
{
	if (c == map_params->empty_ch)
		return (1);
	if (c == map_params->obstacle_ch)
		return (1);
	return (0);
}

int	check_unique(char *s, t_map *map_params)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0')
	{
		j = i + 1;
		while (s[j] != '\0')
		{
			if (s[j] == s[i])
				return (0);
			++j;
		}
		++i;
	}
	map_params->empty_ch = s[0];
	map_params->obstacle_ch = s[1];
	map_params->full_ch = s[2];
	return (1);
}

int	only_printable_chars(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] >= 32 && s[i] <= 126))
			return (0);
		++i;
	}
	return (1);
}

int	check_set(char *str, t_map *map_params)
{
	t_ui	i;
	char	set[4];
	t_ull	number;

	number = 0;
	i = 0;
	while (str[i++] != '\n')
		;
	if (i - 1 < 4 || str[0] == '0' || str[i] == '\n')
		return (0);
	set_init(set, map_params, str, i);
	while (map_params->m < i - 4)
	{
		if (number >= UINT_MAX)
			return (0);
		if (!(str[map_params->m] >= '0' && str[map_params->m] <= '9'))
			return (0);
		number = number * 10 + ((str[(map_params->m)++]) - '0');
	}
	map_params->n = (t_ui) number;
	if (!check_unique(set, map_params) || !only_printable_chars(set))
		return (0);
	map_params->m = 0;
	return (i);
}

int	map_is_valid(char *str, t_map *map_params)
{
	int		i;
	char	**lines;
	int		flag;

	i = check_set(str, map_params);
	if (i == 0)
		return (0);
	i = cycle_func(str, i, map_params);
	if (!i)
		return (0);
	if (map_params->m != map_params->n)
		return (0);
	init_flag_and_i(&flag, &i);
	lines = ft_split(str, "\n");
	map_params->m = ft_strlen(lines[1]);
	while (lines[i + 2] != 0)
		if (map_params->m != ft_strlen(lines[i++ + 2]))
			flag = 0;
	free_matrix(lines);
	return (flag);
}
