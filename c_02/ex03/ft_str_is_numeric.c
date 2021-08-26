/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:05:36 by strisha           #+#    #+#             */
/*   Updated: 2021/08/06 19:05:40 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (*(str + i) != '\0')
	{
		if (!(*(str + i) >= '0' && *(str + i) <= '9'))
		{
			flag = 0;
			break ;
		}
		i++;
	}
	return (flag);
}
