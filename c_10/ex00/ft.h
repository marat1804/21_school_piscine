/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:25:25 by strisha           #+#    #+#             */
/*   Updated: 2021/08/17 15:11:28 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define BUF_SIZE 4096 
# include <unistd.h>
# include <fcntl.h>
void	putchar(char c);
void	printline(char *str);
int		ft_display_file(char *filename);
#endif
