/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 14:25:34 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/19 16:05:44 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include "ft_ls_struct.h"
# include "ft_ls_define.h"
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <dirent.h>

void		ft_ls_process(t_arg arg, t_list *lst, int end_dir);
int			ft_lsgetfilesindir(t_obj **files, struct dirent *file, \
		char *path, t_arg arg);
void		ft_lsgetfiles(t_obj **files, char *name, char *path, t_arg arg);
void		ft_lsdisplay(t_arg arg, t_obj *files, int fileordir);
t_obj		*ft_lsorganizeobjs(t_obj *list, t_arg arg);
int			ft_namecmp(t_obj *obj1, t_obj *obj2);
int			ft_timecmp(t_obj *obj1, t_obj *obj2);
void		ft_lscpyobj(t_obj **objs, t_obj *to_cpy);
void		ft_lsswapobj(t_obj **a, t_obj **b);

#endif
