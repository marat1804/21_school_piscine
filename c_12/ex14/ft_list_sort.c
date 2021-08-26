/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:57:45 by strisha           #+#    #+#             */
/*   Updated: 2021/08/19 16:48:11 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list -> next;
	}
	return (i);
}

void	if_cond(t_list **prev, t_list **cur, t_list **beg)
{
	t_list	*next;

	if (!(*prev))
	{
		*beg = (*cur)->next;
		*prev = *beg;
	}
	else
	{
		(*prev)->next = (*cur)->next;
		(*prev) = (*prev)->next;
	}	
	next = (*cur)->next->next;
	(*cur)->next->next = *cur;
	(*cur)->next = next;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*prev;
	t_list	*cur;
	int		i;
	int		n;

	n = ft_list_size(*begin_list);
	i = 0;
	while (i < n - 1)
	{
		prev = NULL;
		cur = *begin_list;
		while (cur->next)
		{
			if ((*cmp)(cur->data, cur->next->data) > 0)
				if_cond(&prev, &cur, begin_list);
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
		i++;
	}
}
