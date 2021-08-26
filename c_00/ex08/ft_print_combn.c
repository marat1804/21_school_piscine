/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:35:33 by strisha           #+#    #+#             */
/*   Updated: 2021/08/05 14:13:59 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_norm(int array[], int n)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (i < n - 1)
	{
		if (!(array[i] < array[i + 1]))
		{
			flag = 0;
			break ;
		}
		i++;
	}
	return (flag);
}

void	ft_print_array(int array[], int n)
{
	int		i;

	if (check_norm(array, n))
	{
		i = 0;
		while (i <= n - 1)
		{
			ft_putchar(array[i]);
			i++;
		}
		if (!(array[0] == 9 - n + 1 + '0'))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}	
}

void	ft_create_while(int array[], int cn, int n)
{
	if (cn == n - 1)
	{
		array[cn] = '0';
		while (array[cn] <= '9')
		{
			ft_print_array(array, n);
			array[cn]++;
		}	
	}
	else
	{
		if (cn == 0)
		{
			array[cn] = '0';
		}
		else
		{
			array[cn] = array[cn - 1] + 1;
		}
		while (array[cn] <= '9')
		{
			ft_create_while(array, cn + 1, n);
			array[cn]++;
		}	
	}
}

void	ft_print_combn(int n)
{
	int	array[10];

	ft_create_while(array, 0, n);
}
