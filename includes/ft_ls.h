/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 14:25:34 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/21 16:25:02 by psebasti         ###   ########.fr       */
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

void		ft_lsprocess(t_arg arg, t_list *list, int end_dir);
int			ft_lsgetobjsindir(t_obj **files, struct dirent *file, \
		char *path, t_arg arg);
void		ft_lsgetfiles(t_obj **files, char *name, char *path, t_arg arg);
void		ft_lsdisplay(t_arg arg, t_obj *files, int fileordir);
t_obj		*ft_lsorganizeobjs(t_obj *list, t_arg arg);
int			ft_namecmp(t_obj *obj1, t_obj *obj2);
int			ft_timecmp(t_obj *obj1, t_obj *obj2);
void		ft_lscpyobj(t_obj **objs, t_obj *to_cpy);
void		ft_lsswapobj(t_obj **a, t_obj **b);
void		ft_color_mode(mode_t mode);
t_disp_size	ft_lslongsize(t_arg arg, t_obj *files);
void		ft_lsprintchmod(t_obj *obj);
void		ft_lsprintfilemode(t_obj *obj);
void		ft_lsprintint(int nlink, int space);
void		ft_lsprintstr(char *str, int space);
void		ft_lsprintmajmin(t_obj *file, t_disp_size size);
void		ft_lsR(t_arg arg, t_obj *files);
void		ft_lsdelpath(void *path, size_t size);
void		ft_lsdelobj(t_obj **alst);
void		ft_lsdelobjdisplay(t_obj **alst);

#endif
