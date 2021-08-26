/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_stdin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:08:18 by strisha           #+#    #+#             */
/*   Updated: 2021/08/25 14:00:51 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*ft_realloc(char *str, t_ui *buf_size, t_ui *flag)
{
	char	*res;
	int		i;

	res = (char *)malloc((*buf_size * 2 + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		res[i] = str[i];
		++i;
	}
	res[i] = '\0';
	*flag = i;
	free (str);
	*buf_size = *buf_size * 2;
	return (res);
}

int	check_str(char *str, t_map *map, int cnt)
{
	t_ui	len;
	int		i;

	len = 0;
	if (map->n == 0)
	{
		i = check_set(str, map) > 0;
		if (i == 0)
			return (0);
		map->map = (char **)malloc((map->n) * sizeof(char *));
		return (1);
	}
	i = 0;
	while (str[i] != '\n')
	{
		if (!check_in_set(str[i++], map))
			return (0);
		++len;
	}
	if (map->m == 0 && len != 0)
		map->m = len;
	else if (len == 0 || len != map->m)
		return (0);
	map->map[cnt - 1] = ft_strdup(str);
	return (1);
}

int	input_line(char **buf, t_ui *buf_size, t_map *map, t_ui *cnt)
{
	t_ui	r;
	t_ui	flag2;

	r = 0;
	flag2 = 0;
	while (1)
	{
		r = read(1, *buf + r, *buf_size - r);
		if (r < *buf_size - flag2)
		{
			(*buf)[flag2 + r] = '\0';
			if (!check_str((*buf), map, *cnt))
				return (0);
			++(*cnt);
			break ;
		}
		if (r == *buf_size)
			*buf = ft_realloc(*buf, buf_size, &flag2);
	}
	return (1);
}

int	read_stdin(t_map *map, char **buf, t_ui *buf_size)
{
	int		flag;
	t_ui	cnt;

	flag = 1;
	cnt = 0;
	while (1)
	{
		flag = input_line(buf, buf_size, map, &cnt);
		if (cnt == map->n + 1 || !flag)
		{
			if (!flag)
			{
				write(2, "map error\n", 10);
				return (0);
			}
			return (1);
		}
	}
	return (1);
}

int	read_from_input(void)
{
	t_map	map;
	char	*buf;
	t_ui	buf_size;
	int		flag;

	buf_size = 64;
	map.n = 0;
	buf = (char *)malloc((buf_size + 1) * sizeof(char));
	if (buf == NULL)
		return (0);
	flag = read_stdin(&map, &buf, &buf_size);
	free(buf);
	if (!flag)
		return (1);
	map_find_and_display(map.map, map);
	free_map(map);
	return (0);
}
