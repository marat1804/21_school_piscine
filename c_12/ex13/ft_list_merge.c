/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:37:53 by strisha           #+#    #+#             */
/*   Updated: 2021/08/19 10:56:31 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;

	if (*begin_list1 == begin_list2)
		return ;
	if (*begin_list1)
	{
		current = *begin_list1;
		while (current->next)
			current = current->next;
		current->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}
