/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:52:55 by strisha           #+#    #+#             */
/*   Updated: 2021/08/17 18:36:13 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_length(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_swap(char **x, char **y)
{
	char	*tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	size;

	size = get_length(tab);
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_swap(tab + j, tab + j + 1);
			j++;
		}
		i++;
	}
}
