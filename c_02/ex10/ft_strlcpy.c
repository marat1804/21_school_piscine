/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:58:38 by strisha           #+#    #+#             */
/*   Updated: 2021/08/07 22:31:19 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	str_len_(char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = str_len_(src);
	if (size == 0)
		return (len);
	i = 0;
	while (*(src + i) != '\0' && i < size)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (i < size)
		*(dest + i) = '\0';
	else
		*(dest + size - 1) = '\0';
	return (len);
}
