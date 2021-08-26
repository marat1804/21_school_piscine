/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:07:27 by strisha           #+#    #+#             */
/*   Updated: 2021/08/06 10:57:47 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (*(str + i) != '\0')
	{
		if (!(*(str + i) >= 'a' && *(str + i) <= 'z'))
		{
			if (!(*(str + i) >= 'A' && *(str + i) <= 'Z'))
			{
				flag = 0;
				break ;
			}
		}
		i++;
	}
	return (flag);
}
