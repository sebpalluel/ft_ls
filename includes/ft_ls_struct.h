/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 14:29:44 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/18 14:32:25 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_STRUCT_H
# define FT_LS_STRUCT_H

typedef struct		s_ls
{
	char			mode[15];
	int				links;
	char			*own;
	char			*group;
	int				major;
	long long		size;
	long long		blocks;
	long			date;
	char			*name;
	char			*linkpath;
	int				not_a_dir;
}					t_ls;

#endif
