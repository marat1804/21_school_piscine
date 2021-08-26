/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:24:43 by strisha           #+#    #+#             */
/*   Updated: 2021/08/17 17:14:19 by strisha          ###   ########.fr       */
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

int	is_stdio(char *str)
{
	if (str[0] == '-' && str[1] == '-' && str[2] == '\0')
		return (1);
	return (0);
}
