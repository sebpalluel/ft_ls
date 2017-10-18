/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 14:29:44 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/18 16:52:27 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_STRUCT_H
# define FT_LS_STRUCT_H

# include <sys/stat.h>
# include <sys/types.h>

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
	int				R;
	int				a;
	int				r;
	int				t;
}					t_arg;

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
	struct s_ls		*next;
}					t_ls;

#endif
