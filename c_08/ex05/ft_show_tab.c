/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:54:53 by strisha           #+#    #+#             */
/*   Updated: 2021/08/14 13:08:41 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	putchar(char c)
{
	write(1, &c, 1);
}

void	printline(char *s)
{
	while (*s)
	{
		putchar(*s);
		s++;
	}
}

void	put_int_min(void)
{
	putchar('-');
	putchar('2');
	putchar('1');
	putchar('4');
	putchar('7');
	putchar('4');
	putchar('8');
	putchar('3');
	putchar('6');
	putchar('4');
	putchar('8');
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		put_int_min();
	else
	{
		if (nb < 0)
		{
			putchar('-');
			nb = nb * -1;
		}
		if (nb < 10)
			putchar(nb + '0');
		else
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		printline(par[i].str);
		putchar('\n');
		ft_putnbr(par[i].size);
		putchar('\n');
		printline(par[i].copy);
		putchar('\n');
		i++;
	}
}		
