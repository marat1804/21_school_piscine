/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:32:04 by strisha           #+#    #+#             */
/*   Updated: 2021/08/17 17:50:27 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_op(char c)
{
	if (c == '+')
		return (0);
	else if (c == '-')
		return (1);
	else if (c == '*')
		return (2);
	else if (c == '/')
		return (3);
	else if (c == '%')
		return (4);
	else
		return (5);
}

int	check(char op, int b)
{
	if (op == '/' && b == 0)
	{
		putstr("Stop : division by zero\n");
		return (0);
	}
	if (op == '%' && b == 0)
	{
		putstr("Stop : modulo by zero\n");
		return (0);
	}
	return (1);
}

int	ft_doop(int num1, char op, int num2)
{
	int	(*g[5])(int, int);
	int	temp;

	g[0] = op_plus;
	g[1] = op_minus;
	g[2] = op_mul;
	g[3] = op_division;
	g[4] = op_modulo;
	temp = get_op(op);
	if (temp == 5)
		return (0);
	return ((*g[temp])(num1, num2));
}

void	calc(char *number1, char *op, char *number2)
{
	int	res;

	if (check(op[0], ft_atoi(number2)))
	{
		res = ft_doop(ft_atoi(number1), op[0], ft_atoi(number2));
		ft_putnbr(res);
		ft_putchar('\n');
	}
}
