/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:44:58 by strisha           #+#    #+#             */
/*   Updated: 2021/08/18 15:22:56 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	if (nbr == 0)
		return (begin_list);
	i = 0;
	while (i < nbr)
	{
		if (!begin_list)
			return (NULL);
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}
