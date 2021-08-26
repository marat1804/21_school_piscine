/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:07:11 by strisha           #+#    #+#             */
/*   Updated: 2021/08/12 17:13:59 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_size;

	dest_size = 0;
	while (dest[dest_size] != '\0')
		dest_size++;
	while (*src != '\0')
	{
		dest[dest_size] = *src;
		dest_size++;
		src++;
	}
	dest[dest_size] = '\0';
	return (dest);
}

int	res_size(int size, char **strs, char *sep)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (i < size)
	{	
		length += ft_strlen(strs[i]);
		i++;
	}
	length += (size - 1) * ft_strlen(sep);
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		length;
	int		i;
	char	*res;

	if (size == 0)
	{
		res = (char *)malloc(sizeof(char));
		*res = '\0';
		return (res);
	}
	length = res_size(size, strs, sep);
	res = (char *) malloc(sizeof(char) * (length + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	*res = '\0';
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		if (i + 1 < size)
			ft_strcat(res, sep);
		i++;
	}
	return (res);
}
