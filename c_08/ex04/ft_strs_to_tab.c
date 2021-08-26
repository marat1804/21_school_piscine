/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 11:34:36 by strisha           #+#    #+#             */
/*   Updated: 2021/08/14 13:09:32 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
int	strlen_(char *src)
{
	int	i;

	i = 0;
	while (*src)
	{
		i++;
		src++;
	}
	return (i);
}

void	copy(t_stock_str *a, int i, char **av)
{
	int	size;
	int	j;

	size = strlen_(av[i]);
	a[i].size = size;
	a[i].str = av[i];
	a[i].copy = (char *)malloc(sizeof(char) * (size + 1));
	j = 0;
	while (av[i][j])
	{
		a[i].copy[j] = av[i][j];
		j++;
	}
	a[i].copy[j] = '\0';
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*a;
	int			i;

	a = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (a == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		copy(a, i, av);
		i++;
	}
	a[i].str = 0;
	a[i].copy = 0;
	a[i].size = 0;
	return (a);
}
