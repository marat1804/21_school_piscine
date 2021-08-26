/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:19:21 by strisha           #+#    #+#             */
/*   Updated: 2021/08/14 14:54:20 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	char	*cursym;

	cursym = str;
	while (*cursym != '\0')
	{
		ft_putchar(*cursym);
		cursym++;
	}
}
