/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:21:07 by strisha           #+#    #+#             */
/*   Updated: 2021/08/17 18:01:31 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>

int		op_plus(int a, int b);
int		op_modulo(int a, int b);
int		op_minus(int a, int b);
int		op_division(int a, int b);
void	ft_putnbr(int nbr);
int		ft_atoi(char *str);
int		op_mul(int a, int b);
void	putstr(char *str);
void	calc(char *number1, char *op, char *number2);
char	ft_putchar(char c);
#endif
