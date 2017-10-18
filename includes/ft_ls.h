/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 14:25:34 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/18 14:35:00 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../../libft/includes/libft.h"
# include "includes/ft_ls_struct.h"
# include "includes/ft_ls_define.h"
# include <time.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <dirent.h>

void				ft_ls(const char *path, const char *flags, int args);
t_list				*ft_ls_back(const char *path, const char *flags);
void				ft_ls_front(const t_list *lst, const char *flags, \
					const char *path, int args);
void				ft_ls_rec(const t_list *lst, const char *path, \
					const char *flags);
t_list				*ft_ls_sort(t_list *lst, const char *flags);
void				ft_ls_args(int ac, char **av, int first, const char *flags);
int					ft_ls_error_file_dir(const char *path);
t_list				*ft_ls_listsort(t_list *lst, int (*cmp)(void*, void*));
long				errors(const int error, const char *letter);
int					ft_ls_colors(const t_pls *info, const char *flags);
t_list				*ft_ls_back_args_sort(t_list *lst, const char *flags);
void				free_lst(void *inf, size_t size);


#endif
