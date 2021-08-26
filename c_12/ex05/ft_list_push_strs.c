/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:15:47 by strisha           #+#    #+#             */
/*   Updated: 2021/08/18 15:17:56 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*tmp;
	t_list	*list;
	int		i;

	i = 0;
	while (i < size)
	{
		if (i == 0)
			list = ft_create_elem(strs[i]);
		else
		{
			tmp = ft_create_elem(strs[i]);
			tmp->next = list;
			list = tmp;
		}
		i++;
	}
	return (list);
}
