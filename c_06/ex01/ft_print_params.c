/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:21:45 by strisha           #+#    #+#             */
/*   Updated: 2021/08/11 10:46:42 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	printchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	k;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			k = 0;
			while (argv[i][k])
			{
				printchar(argv[i][k]);
				k++;
			}
			printchar('\n');
			i++;
		}
	}
	return (0);
}
