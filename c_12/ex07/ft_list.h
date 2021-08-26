/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:12:56 by strisha           #+#    #+#             */
/*   Updated: 2021/08/18 15:20:07 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}		t_list;

t_list	*ft_create_elem(void *data);
#endif
