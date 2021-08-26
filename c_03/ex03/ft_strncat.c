/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 10:58:34 by strisha           #+#    #+#             */
/*   Updated: 2021/08/08 11:08:50 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	int	dest_size;
	int	i;

	dest_size = 0;
	i = 0;
	while (dest[dest_size])
		dest_size++;
	while (src[i] != '\0' && (unsigned int) i < n)
	{
		dest[dest_size] = src[i];
		dest_size++;
		i++;
	}
	dest[dest_size] = '\0';
	return (dest);
}	
