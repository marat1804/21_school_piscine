/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 11:16:59 by strisha           #+#    #+#             */
/*   Updated: 2021/08/08 11:57:53 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*b;
	char	*a;

	if (*to_find == '\0')
		return (str);
	b = to_find;
	while (*str != '\0')
	{
		if (*str == *b)
		{
			a = str;
			while (*a == *b)
			{
				if (*(b + 1) == '\0')
					return (str);
				a++;
				b++;
			}
			b = to_find;
		}
		str++;
	}
	return (0);
}
