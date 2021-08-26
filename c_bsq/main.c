/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:15:07 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/25 17:37:29 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*ft_map_copy(char *file, int count)
{
	int		fd;
	char	*res;

	res = (char *)malloc((count + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error(1);
	if (read(fd, res, count) == -1)
		print_error(2);
	res[count] = '\0';
	if (close(fd) == -1)
		print_error(3);
	return (res);
}

char	*ft_map(char *file)
{
	int		fd;
	int		d;
	int		count;
	char	buf[4096];

	d = 1;
	fd = open(file, O_RDONLY);
	count = 0;
	if (fd == -1)
		print_error(1);
	while (1)
	{
		d = read(fd, buf, 4096);
		if (d == -1)
			print_error(2);
		if (d > 0)
			count += d;
		if (d == 0)
			break ;
	}
	if (close(fd) == -1)
		print_error(3);
	return (ft_map_copy(file, count));
}

t_ui	ft_strlen(char *s)
{
	t_ui	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

void	read_from_file(int argc, char **argv)
{
	int		i;
	char	*str;
	t_map	map;
	char	**lines;

	i = 1;
	while (i < argc)
	{
		str = ft_map(argv[i]);
		if (!map_is_valid(str, &map))
		{
			++i;
			write(2, "map error\n", 10);
			continue ;
		}
		lines = ft_split(str, "\n");
		map_find_and_display(lines + 1, map);
		free_matrix(lines);
		++i;
		free(str);
	}
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc < 2)
	{
		i = read_from_input();
		return (i);
	}
	else
		read_from_file(argc, argv);
	return (0);
}
