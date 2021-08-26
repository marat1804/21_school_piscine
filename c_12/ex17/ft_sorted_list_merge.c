/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:44:37 by strisha           #+#    #+#             */
/*   Updated: 2021/08/19 18:51:45 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, t_list *elem, int (*cmp)())
{
	t_list	*prev;
	t_list	*next;

	if (!(*begin_list))
		*begin_list = elem;
	else
	{
		prev = *begin_list;
		if (cmp(elem->data, prev->data) <= 0)
		{
			*begin_list = elem;
			(*begin_list)->next = prev;
			return ;
		}
		while (prev->next)
		{
			if (cmp(elem->data, prev->next->data) <= 0)
				break ;
			prev = prev->next;
		}
		next = prev->next;
		prev->next = elem;
		prev->next->next = next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*elem;
	t_list	*next;

	if (*begin_list1)
	{
		elem = begin_list2;
		next = elem->next;
		while (elem)
		{
			elem->next = NULL;
			ft_sorted_list_insert(begin_list1, elem, cmp);
			elem = next;
			if (next)
				next = elem->next;
		}
	}
	else
		*begin_list1 = begin_list2;
}
