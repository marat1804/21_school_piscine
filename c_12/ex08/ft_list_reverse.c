/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:30:45 by strisha           #+#    #+#             */
/*   Updated: 2021/08/19 11:43:47 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*new;

	if ((*begin_list) || ((*begin_list)->next))
	{
        new = (void *)0;
		while (*begin_list)
		{
			tmp = (*begin_list)->next;
			(*begin_list)->next = new;
			new = *begin_list;
			*begin_list = tmp;
		}
		*begin_list = new;
	}
}
