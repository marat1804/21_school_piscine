/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:13:09 by strisha           #+#    #+#             */
/*   Updated: 2021/08/17 15:38:31 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

void	puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, str + i, 1);
		i++;
	}
}

void	display_error(int err, char **argv, int i)
{
	puterror(basename(argv[0]));
	puterror(": ");
	puterror(argv[i]);
	puterror(": ");
	puterror(strerror(err));
	puterror("\n");
}

void	display_custom_error(char **argv, char *str, char *str2)
{
	puterror(basename(argv[0]));
	puterror(": ");
	puterror(str);
	puterror(" ");
	puterror(str2);
	puterror("\n");
}

void	print_stdin(char *str, int end, int flag, int num)
{
	if (flag)
	{
		write(1, str + end, num - end);
		write(1, str, end);
	}
	else
	{
		write(1, str, end);
	}
}
