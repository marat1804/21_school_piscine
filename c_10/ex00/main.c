/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:26:53 by strisha           #+#    #+#             */
/*   Updated: 2021/08/17 15:16:17 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	printerr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, str + i, 1);
		i++;
	}
}

void	printline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

int	ft_display_file(char *filename)
{
	int		fd;
	char	buffer[BUF_SIZE];
	int		r;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printerr("Cannot read file.\n");
		return (1);
	}
	while (1)
	{
		r = read(fd, &buffer, BUF_SIZE);
		if (r == 0)
			break ;
		write(1, &buffer, r);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_display_file(argv[1]) > 0)
			return (1);
	}
	else
	{
		if (argc <= 1)
			printerr("File name missing.\n");
		if (argc > 2)
			printerr("Too many arguments.\n");
		return (1);
	}
	return (0);
}
