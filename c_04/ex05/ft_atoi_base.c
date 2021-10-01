/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:26:27 by strisha           #+#    #+#             */
/*   Updated: 2021/08/10 11:46:34 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (*base)
	{
		if (!(*base > 32 && *base <= 126))
			return (0);
		if (*base == '-' || *base == '+')
			return (0);
		j = 1;
		while (*(base + j))
		{
			if (*base == *(base + j))
				return (0);
			j++;
		}
		i++;
		base++;
	}
	if (i < 2)
		return (0);
	else
		return (i);
}

int	find_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
		return 0
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	basen;

	sign = 1;
	result = 0;
	basen = check_base(base);
	if (basen == 0)
		return (0);
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'\
		   || *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (find_char(base, *str))
	{
		result = result * basen + find_char(base, *str);
		str++;
	}
	result *= sign;
	return (result);
}
