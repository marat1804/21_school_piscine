/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:12:36 by strisha           #+#    #+#             */
/*   Updated: 2021/08/10 16:52:38 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}	

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	while (nb < 2147483647)
	{
		if (is_prime(nb))
			return (nb);
		nb++;
	}
	return (2147483647);
}
