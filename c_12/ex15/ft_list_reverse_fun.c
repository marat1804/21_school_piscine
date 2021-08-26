/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_run.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:49:15 by strisha           #+#    #+#             */
/*   Updated: 2021/08/19 17:16:48 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	list_size(t_list *beg)
{
	int	i;

	i = 0;
	while (beg)
	{
		i++;
		beg = beg->next;
	}
	return (i);
}

void	if_cond(t_list **tmp, t_list **next)
{
	void	*data;

	data = (*tmp)->data;
	(*tmp)->data = (*next)->data;
	(*next)->data = data;
	(*tmp) = (*tmp)->next;
	(*next) = (*next)->next;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*tmp;
	t_list	*next;
	int		i;
	int		len;

	if (begin_list && begin_list->next)
	{
		len = list_size(begin_list);
		while (len > 0)
		{
			i = 0;
			tmp = begin_list;
			next = begin_list->next;
			while (next && i < len - 1)
			{
				if_cond(&tmp, &next);
				i++;
			}
			len--;
		}
	}
}
