#include "ft_btree.h"
# define MAX(a,b) ((a > b) ? a : b)

int		btree_level_count(t_btree *root)
{
	if (root)
		return (1 + MAX(btree_level_count(root->left), \
				btree_level_count(root->right)));
	return (0);
}

void	btree_process_level(t_btree *root, int *t, int level,
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!root)
		return ;
	if (level == 1)
	{
		applyf(root->item, t[0], t[1]);
		t[1] = 0;
	}
	else if (level > 1)
	{
		btree_process_level(root->left, t, level - 1, applyf);
		btree_process_level(root->right, t, level - 1, applyf);
	}
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	int t[3];
	int h;
	int i;

	if (root)
	{
		h = btree_level_count(root);
		i = 0;
		while (i < h)
		{
			t[0] = i;
			t[1] = 1;
			btree_process_level(root, t, ++i, applyf);
		}
	}
}
