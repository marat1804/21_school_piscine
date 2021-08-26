/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:06:52 by strisha           #+#    #+#             */
/*   Updated: 2021/08/19 16:26:45 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	if_cond(t_list **current, t_list **last, t_list **begin_list,
		void (*free_fct)(void *))
{
	if (*current == *begin_list)
	{
		*begin_list = (*current)->next;
		if ((*current)->data)
			(*free_fct)((*current)->data);
		free(*current);
		(*current) = (*begin_list)->next;
	}
	else
	{
		(*last)->next = (*current)->next;
		if ((*current)->data)
			(*free_fct)((*current)->data);
		free(*current);
		*current = (*last)->next;
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*last;
	t_list	*current;

	last = NULL;
	current = *begin_list;
	while (current)
	{
		if ((*cmp)(current -> data, data_ref) == 0)
		{
			if_cond(&current, &last, begin_list, free_fct);
		}
		else
		{
			last = current;
			current = current->next;
		}
	}
}
