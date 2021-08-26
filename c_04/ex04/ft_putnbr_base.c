/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:28:40 by strisha           #+#    #+#             */
/*   Updated: 2021/08/10 17:43:44 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (*base)
	{
		if (!(*base >= 32 && *base <= 126))
			return (0);
		if (*base == '-' || *base == '+')
			return (0);
		j = 1;
		while (*(base + j))
		{
			if (*base == *(base + j))
				return (0);
			j++;
		}
		i++;
		base++;
	}
	if (i < 2)
		return (0);
	else
		return (i);
}

void	ft_putnbr(int nbr, char *base, int basen)
{
	if (nbr != 0)
	{
		ft_putnbr(nbr / basen, base, basen);
		ft_putchar(*(base - nbr % basen));
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	basen;

	basen = check_base(base);
	if (basen)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			ft_putnbr(nbr, base, basen);
		}
		else
		{
			if (nbr == 0)
				ft_putchar(*base);
			else
				ft_putnbr(-nbr, base, basen);
		}
	}
}
