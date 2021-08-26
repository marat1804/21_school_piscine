/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:45:39 by strisha           #+#    #+#             */
/*   Updated: 2021/08/17 17:14:13 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>
# define BUF_SIZE 4096
void	display_error(int err, char **argv, int i);
void	putstr(char *str);
int		is_stdio(char *str);
#endif
