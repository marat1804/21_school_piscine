/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:33:03 by strisha           #+#    #+#             */
/*   Updated: 2021/08/20 11:50:23 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	t_btree	*res;

	res = NULL;
	if (root != NULL)
	{
		res = btree_search_item(root->left, data_ref, cmpf);
		if (res == NULL && (*cmpf)(root->item, data_ref) == 0)
			res = root->item;
		if (!res)
			res = btree_search_item(root->right, data_ref, cmpf);
	}
	return (res);
}
