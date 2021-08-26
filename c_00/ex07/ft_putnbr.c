/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:10:26 by strisha           #+#    #+#             */
/*   Updated: 2021/08/05 13:43:15 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_int_min(void)
{
	ft_putchar('-');
	ft_putchar('2');
	ft_putchar('1');
	ft_putchar('4');
	ft_putchar('7');
	ft_putchar('4');
	ft_putchar('8');
	ft_putchar('3');
	ft_putchar('6');
	ft_putchar('4');
	ft_putchar('8');
}

void	ft_print_number(int nb)
{
	int	size;
	int	tmp;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	tmp = nb;
	while (tmp > 10)
	{
		size = size * 10;
		tmp = tmp / 10;
	}
	while (size > 0)
	{
		ft_putchar(nb / size + '0');
		nb = nb % size;
		size = size / 10;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		ft_print_int_min();
	else
	{
		if (nb == 0)
			ft_putchar('0');
		else
		{
			ft_print_number(nb);
		}
	}
}
