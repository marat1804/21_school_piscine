/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:18:47 by strisha           #+#    #+#             */
/*   Updated: 2021/08/19 17:42:41 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*prev;
	t_list	*next;

	if (!(*begin_list))
		*begin_list = ft_create_elem(data);
	else
	{
		prev = *begin_list;
		if (cmp(data, prev->data) <= 0)
		{
			*begin_list = ft_create_elem(data);
			(*begin_list)->next = prev;
			return ;
		}
		while (prev->next)
		{
			if (cmp(data, prev->next->data) <= 0)
				break ;
			prev = prev->next;
		}
		next = prev->next;
		prev->next = ft_create_elem(data);
		prev->next->next = next;
	}
}
