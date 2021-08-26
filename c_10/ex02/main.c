/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:52:28 by strisha           #+#    #+#             */
/*   Updated: 2021/08/17 13:34:29 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int	check_c_param(int argc, char **argv, int *file)
{
	int	res;

	res = -1;
	if (argv[1][2] != '\0')
	{
		res = ft_atoi(argv[1] + 2);
		*file = 2;
		if (res == -1)
			display_custom_error(argv, "illegal offset --", argv[1] + 2);
	}
	else
	{
		if (argc > 2)
		{
			res = ft_atoi(argv[2]);
			*file = 3;
		}
		else
			res = -2;
		if (res == -1)
			display_custom_error(argv, "illegal offset --", argv[2]);
		if (res == -2)
			display_custom_error(argv, "option requires an argument", "-- c");
	}
	return (res);
}

int	check_arg(int argc, char **argv, int *filestart)
{
	int	i;

	i = -1;
	if (argc < 2)
		return (-1);
	if (argv[1][0] == '-' && argv[1][1] == 'c')
	{
		i = check_c_param(argc, argv, filestart);
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int	res;
	int	file;

	res = check_arg(argc, argv, &file);
	if (res > 0)
	{
		if (file == argc)
			ft_stdin(res);
		else
			print_files(argc, argv, file, res);
	}
	if (errno)
		return (1);
	return (0);
}
