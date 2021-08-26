/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 10:04:12 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/25 13:35:16 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*ft_strdup(char *s)
{
	t_ui		size;
	t_ui		i;
	char		*res;

	size = ft_strlen(s);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = s[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

void	print_error(int exit_val)
{
	write(2, "map error\n", 10);
	exit (exit_val);
}

void	set_init(char set[4], t_map *map, char *str, int i)
{
	map->n = 0;
	map->m = 0;
	set[3] = '\0';
	set[2] = str[i - 2];
	set[1] = str[i - 3];
	set[0] = str[i - 4];
}
