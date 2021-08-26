/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:53:31 by strisha           #+#    #+#             */
/*   Updated: 2021/08/17 14:01:56 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>
# include <stdlib.h>

void	putstr(char *str);
int		ft_atoi(char *str);
void	puterror(char *str);
void	display_error(int err, char **argv, int i);
void	display_custom_error(char **argv, char *str, char *str2);
void	print_stdin(char *str, int end, int flag, int num);
void	ft_stdin(int num);
void	print_files(int argc, char **argv, int file, int num);
void	init_with_zero(int *a, int *b);
#endif
