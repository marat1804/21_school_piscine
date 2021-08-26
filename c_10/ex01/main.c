/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:26:11 by strisha           #+#    #+#             */
/*   Updated: 2021/08/17 17:15:35 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

void	ft_stdin(void)
{
	char	buffer[BUF_SIZE];
	int		prev;
	int		cur;

	prev = 1;
	while (1)
	{
		cur = read(0, &buffer, BUF_SIZE);
		if (cur)
		{
			write(1, &buffer, cur);
		}
		else
		{
			if (prev == 0)
				break ;
		}
		if (cur < BUF_SIZE)
			prev = 0;
	}
}

int	print(int fd, char **argv, int i)
{
	int		r;
	char	buffer[BUF_SIZE];

	r = read(fd, &buffer, BUF_SIZE);
	if (r == -1)
	{
		display_error(errno, argv, i);
		return (1);
	}
	else
	{
		if (r == 0)
			return (1);
		else
			write(1, &buffer, r);
	}
	return (0);
}

void	display_files(char **argv, int i)
{
	int		fd;
	int		r;

	fd = open(argv[i], O_RDONLY);
	if (fd == -1)
		display_error(errno, argv, i);
	else
	{
		while (1)
		{
			r = print(fd, argv, i);
			if (r)
				break ;
		}
		r = close(fd);
		if (r == -1)
			display_error(errno, argv, i);
	}
}

void	print_files(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			ft_stdin();
		else if (i == 1 && is_stdio(argv[i]))
			ft_stdin();
		else
			display_files(argv, i);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_stdin();
	else
		print_files(argc, argv);
	if (errno)
		return (1);
	return (0);
}
