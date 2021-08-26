/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 12:01:16 by strisha           #+#    #+#             */
/*   Updated: 2021/08/08 14:14:23 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

unsigned int	str_len_(char *s)
{
	unsigned int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	res;
	int				i;

	i = 0;
	res = str_len_(dest);
	while (src[i] != '\0' && (unsigned int)i + res < size)
	{
		dest[res + i] = src[i];
		i++;
	}
	if (i + res < size)
	{
		dest[res + i] = '\0';
	}
	else
		dest[size - 1] = '\0';
	return (res + str_len_(src));
}
