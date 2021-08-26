/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 20:31:48 by strisha           #+#    #+#             */
/*   Updated: 2021/08/06 21:01:03 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(char c)
{
	int	first;
	int	second;

	first = c / 16;
	second = c % 16;
	ft_putchar('\\');
	if (first < 10)
		ft_putchar('0' + first);
	else
		ft_putchar('a' + first - 10);
	if (second < 10)
		ft_putchar('0' + second);
	else
		ft_putchar('a' + second - 10);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) < 32 || *(str + i) > 127)
			print_hex(*(str + i));
		else
			ft_putchar(*(str + i));
		i++;
	}
}
