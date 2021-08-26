/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:09:35 by strisha           #+#    #+#             */
/*   Updated: 2021/08/17 16:40:29 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>
void	ft_stdin(int num)
{
	char	*buf;
	int		flag;
	int		end;
	int		status;

	init_with_zero(&flag, &end);
	buf = (char *)malloc(sizeof(char) * num);
	while (1)
	{
		status = read(0, buf + end, num - end);
		end = end + status;
		if (end == num)
		{
			end = 0;
			flag = 1;
		}
		if (status == 0)
		{
			print_stdin(buf, end, flag, num);
			break ;
		}
	}
	free(buf);
}

void	read_from_file(int fd, int num)
{
	char	*buf;
	int		flag;
	int		end;
	int		status;

	init_with_zero(&flag, &end);
	buf = (char *)malloc(sizeof(char) * num);
	while (1)
	{
		status = read(fd, buf + end, num - end);
		end = end + status;
		if (end == num)
		{
			end = 0;
			flag = 1;
		}
		if (status == 0)
		{
			print_stdin(buf, end, flag, num);
			break ;
		}
		if (status == -1)
			break ;
	}
	free(buf);
}

void	display_files(char **argv, int i, int num)
{
	int		fd;
	int		r;

	fd = open(argv[i], O_RDONLY);
	if (fd == -1)
		display_error(errno, argv, i);
	else
	{
		read_from_file(fd, num);
		r = close(fd);
		if (r == -1)
			display_error(errno, argv, i);
	}
}

void	print_file_name(char *str, int file, int i, int *prev)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		if (i != file && (*prev) != -1)
			putstr("\n");
		putstr("==> ");
		putstr(str);
		putstr(" <==\n");
		*prev = 0;
	}
	if (i == file && fd == -1)
		*prev = fd;
}

void	print_files(int argc, char **argv, int file, int num)
{
	int		i;
	int		prev;

	i = file;
	prev = 0;
	while (i < argc)
	{
		if (file + 1 != argc)
			print_file_name(argv[i], file, i, &prev);
		display_files(argv, i, num);
		i++;
	}
}
