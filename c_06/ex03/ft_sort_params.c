/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:21:45 by strisha           #+#    #+#             */
/*   Updated: 2021/08/12 18:42:25 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	printchar(char c)
{
	write(1, &c, 1);
}

void	sort_params(char *argv[], int argc)
{
	int		i;
	int		k;
	char	*tmp;

	i = 1;
	while (i < argc - 1)
	{
		k = i + 1;
		while (k < argc)
		{
			if (ft_strcmp(argv[i], argv[k]) > 0)
			{
				tmp = argv[k];
				argv[k] = argv[i];
				argv[i] = tmp;
			}
			k++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	k;

	if (argc > 1)
	{
		sort_params(argv, argc);
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
