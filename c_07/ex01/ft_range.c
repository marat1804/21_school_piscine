/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 10:41:32 by strisha           #+#    #+#             */
/*   Updated: 2021/08/12 15:56:10 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*res;

	if (min >= max)
		return (NULL);
	res = (int *) malloc(sizeof(int) * (max - min));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (min < max)
		res[i++] = min++;
	return (res);
}
