/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:18:58 by strisha           #+#    #+#             */
/*   Updated: 2021/08/13 20:39:28 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_itoa_base(int num, char *base_to);

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'\
		   || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (*base)
	{
		if (is_space(*base))
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
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
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
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (find_char(base, *str) >= 0)
	{
		result = result * basen + find_char(base, *str);
		str++;
	}
	result *= sign;
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*res;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (0);
	num = ft_atoi_base(nbr, base_from);
	res = ft_itoa_base(num, base_to);
	return (res);
}
