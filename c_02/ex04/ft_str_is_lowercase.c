/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 11:21:58 by strisha           #+#    #+#             */
/*   Updated: 2021/08/06 11:22:54 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (*(str + i) != '\0')
	{
		if (!(*(str + i) >= 'a' && *(str + i) <= 'z'))
		{
			flag = 0;
			break ;
		}
		i++;
	}
	return (flag);
}