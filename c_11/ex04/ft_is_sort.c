/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 16:41:29 by strisha           #+#    #+#             */
/*   Updated: 2021/08/18 13:30:00 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cmp_sign(int a, int b)
{
	if (a >= 0 && b >= 0)
		return (0);
	if (a <= 0 && b <= 0)
		return (0);
	return (1);
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	flag;
	int	res;

	i = 0;
	flag = 0;
	if (length > 1)
		flag = f(tab[0], tab[1]);
	while (i < length - 1)
	{
		res = f(tab[i], tab[i + 1]);
		if (cmp_sign(res, flag))
			return (0);
		i++;
	}
	return (1);
}
