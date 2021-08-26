/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:44:42 by strisha           #+#    #+#             */
/*   Updated: 2021/08/05 12:13:09 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	count;
	int	tmp;

	count = 0;
	while (count != size / 2)
	{
		tmp = tab[count];
		tab[count] = tab[size - 1 - count];
		tab[size - 1 - count] = tmp;
		count++;
	}
}
