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

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
    t_list	*last;
    t_list	*current;

    last = ((void *)0);
    current = *begin_list;
    while (current)
    {
        if ((*cmp)(current->data, data_ref) == 0)
        {
            if (current == *begin_list)
                *begin_list = current->next;
            else
                last->next = current->next;
            last = current;
            current = current->next;
            free_fct(last);
        }
        else
        {
            last = current;
            current = current->next;
        }
    }
}
