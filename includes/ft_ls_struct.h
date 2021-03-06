/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 14:29:44 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/25 10:42:52 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_STRUCT_H
# define FT_LS_STRUCT_H

# include <sys/stat.h>
# include <sys/types.h>

typedef struct		s_disp_size
{
	int				total;
	int				size;
	int				grpspace;
	int				usrspace;
	int				lnkspace;
	int				min;
	int				maj;
}					t_disp_size;

typedef struct		s_arg
{
	int				l;
	int				recurse;
	int				a;
	int				r;
	int				t;
	int				u;
	int				g;
	int				f;
}					t_arg;

typedef struct		s_obj
{
	char			*name;
	char			*path;
	time_t			date;
	mode_t			st_mode;
	uid_t			st_uid;
	gid_t			st_gid;
	nlink_t			st_nlink;
	quad_t			st_blocks;
	off_t			st_size;
	int				not_a_dir;
	long			maj;
	long			min;
	char			*lnked_to;
	char			*final_time;
	struct s_obj	*next;
}					t_obj;

#endif
