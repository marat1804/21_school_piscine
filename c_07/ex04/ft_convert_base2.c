/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:42:39 by strisha           #+#    #+#             */
/*   Updated: 2021/08/13 20:47:54 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	check_base(char *base);

int	convert(int num, int *nbr, char *base)
{
	int	i;
	int	basen;

	basen = check_base(base);
	i = 0;
	if (num < 0)
		nbr[32] = -1;
	else
	{
		num *= -1;
		nbr[32] = 1;
	}
	if (num == 0)
	{
		nbr[0] = 0;
		return (1);
	}
	while (num)
	{
		nbr[i] = num % basen;
		num = num / basen;
		i++;
	}
	return (i);
}

void	if_cond(int *nul, int *j, int *nbr, int i)
{
	if (nbr[32] == -1)
	{
		*j = i + 2;
		*nul = i + 1;
	}
	else
	{
		*j = i + 1;
		*nul = i;
	}
}

char	*ft_itoa_base(int num, char *base)
{
	int		nbr[33];
	char	*res;
	int		i;
	int		j;
	int		nul;

	i = convert(num, nbr, base);
	if_cond(&nul, &j, nbr, i);
	res = (char *) malloc(sizeof(char) * (j));
	if (res == NULL)
		return (NULL);
	j = 0;
	if (nbr[32] < 0)
		res[j++] = '-';
	i--;
	while (i >= 0)
		res[j++] = *(base - nbr[i--]);
	res[nul] = '\0';
	return (res);
}
