/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 14:29:44 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/18 15:36:19 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_STRUCT_H
# define FT_LS_STRUCT_H

# include "includes/ft_ls.h"

typedef struct		s_ls
{
	char			*name;
	char			*path;
	time_t			date;
	mode_t			mode_file;
	uid_t			uid;
	gid_t			gid;
	nlink_t			link_count;
	off_t			size;
	quad_t			blocks;
	dev_t			dev_id;
	int				not_a_dir;
}					t_ls;

typedef struct		s_size
{
	int				total;
	int				size;
	int				groupspace;
	int				userspace;
	int				linkspace;
	int				min;
	int				maj;
}					t_size;

typedef struct		s_arg
{
	int				l;
	int				upper_r;
	int				a;
	int				r;
	int				t;
	int				u;
	int				f;
	int				g;
}					t_arg;

#endif
