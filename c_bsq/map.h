/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:34:59 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/25 14:00:21 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define UINT_MAX 4294967295

typedef unsigned int		t_ui;
typedef unsigned long long	t_ull;

typedef struct s_map
{
	t_ui	n;
	t_ui	m;
	char	empty_ch;
	char	obstacle_ch;
	char	full_ch;
	char	**map;
}	t_map;

typedef struct s_square
{
	t_ui	i;
	t_ui	j;
	t_ui	value;
}	t_square;

/*-------MAP-UTILS-------*/
t_ui		**init_cache_matrix(t_ui row, t_ui column, t_ui *j);
void		free_cache_matrix(t_ui **cache, t_ui row);
t_ui		convert_val(t_map map_params, char c);
t_ui		find_min_value(t_ui **cache, t_ui i, t_ui j);
t_square	*init_max_square(void);
void		map_find_and_display(char **map, t_map map_params);
void		display_map(char **map, t_map params);
void		fill_square(char **map, t_map params, t_square *square);
t_map		map_init(t_ui n, t_ui m, char set[4]);
void		map_processing(char **map, t_map map_params, t_square *max_square);

/*-------PREPPROC-UTILS----*/
int			check_in_set(char c, t_map *map_params);
int			check_unique(char *s, t_map *map_params);
int			only_printable_chars(char *s);
int			check_set(char *str, t_map *map_params);
int			map_is_valid(char *str, t_map *map_params);
char		**ft_split(char *s, char *set);
t_ui		ft_strlen(char *s);
void		print_error(int exit_val);
void		ft_putchar(char c);

/*---------FILE-UTILS-------*/
char		**ft_split(char *str, char *set);
void		free_matrix(char **words);
void		init_flag_and_i(int	*flag, int *i);
void		set_init(char set[4], t_map *map, char *str, int i);

/*--------STDIN-UTILS-------*/
int			read_from_input(void);
void		free_map(t_map map);
int			cycle_func(char *str, int i, t_map *map_params);
char		*ft_strdup(char *s);

#endif
