/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:14:47 by strisha           #+#    #+#             */
/*   Updated: 2021/08/05 13:17:35 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *array, int first, int second)
{
	int	tmp;

	tmp = array[first];
	array[first] = array[second];
	array[second] = tmp;
}

int	partition(int *array, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, i, j);
		}
		j++;
	}
	swap(array, i + 1, end);
	return (i + 1);
}

void	quicksort(int *array, int start, int end)
{
	int	mid;

	if (start < end)
	{
		mid = partition(array, start, end);
		quicksort(array, start, mid - 1);
		quicksort(array, mid + 1, end);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	start;
	int	end;

	start = 0;
	end = size - 1;
	quicksort(tab, start, end);
}
