/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:01:58 by strisha           #+#    #+#             */
/*   Updated: 2021/08/07 22:28:29 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_address(unsigned int nbr)
{
	int	i;
	int	a[16];

	i = 0;
	while (i < 16)
	{
		a[i++] = 0;
	}
	i--;
	while (nbr > 0)
	{
		a[i--] = nbr % 16;
		nbr = nbr / 16;
	}
	i = 0;
	while (i < 16)
	{
		if (a[i] < 10)
			ft_putchar('0' + a[i++]);
		else
			ft_putchar('a' + a[i++] - 10);
	}
	ft_putchar(':');
	ft_putchar(' ');
}

void	print_hex(char *addr, unsigned int i, unsigned int size, char *hex)
{
	int	j;

	j = 0;
	while ((j < 16) && (j + i < size))
	{
		ft_putchar(hex[*(addr + i + j) / 16]);
		ft_putchar(hex[*(addr + i + j) % 16]);
		if (j % 2)
			ft_putchar(' ');
		j++;
	}
	while (j < 16)
	{
		ft_putchar(' ');
		j++;
	}
}

void	print_char(char *addr, unsigned int i, unsigned int size)
{
	int	j;

	j = 0;
	while ((j < 16) && (j + i < size))
	{
		if (*(addr + i + j) >= 32 && *(addr + i + j) <= 127)
			ft_putchar(*(addr + i + j));
		else
			ft_putchar('.');
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		print_address((unsigned int)addr);
		print_hex((char *)addr, i, size, "0123456789abcdef");
		print_char((char *)addr, i, size);
		ft_putchar('\n');
		i += 16;
	}	
	return (addr);
}	
