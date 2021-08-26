/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:03:43 by strisha           #+#    #+#             */
/*   Updated: 2021/08/20 10:06:16 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*tree;

	tree = (t_btree *)malloc(sizeof(t_btree));
	if (tree == NULL)
		return (NULL);
	tree->right = NULL;
	tree->left = NULL;
	tree->item = item;
	return (tree);
}
