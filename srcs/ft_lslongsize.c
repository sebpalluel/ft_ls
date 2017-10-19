/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lslongsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:10:39 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/19 22:51:11 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

int					ft_get_max_size(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void				ft_lsdisp_usrgrp_size(t_disp_size *size, t_obj *current)
{
	struct passwd	*pws;
	struct group 	*grp;

	pws = getpwuid(current->st_uid) ? getpwuid(current->st_uid) : NULL;
	if (pws != NULL)
	{
		size->usrspace = ft_get_max_size(ft_strlen(pws->pw_name), \
				size->usrspace);
	}
	else
		size->usrspace = ft_get_max_size(ft_intlen(current->st_uid), \
				size->usrspace);
	grp = getgrgid(current->st_gid) ? getgrgid(current->st_gid) : NULL;
	if (grp != NULL)
	{
		size->grpspace = ft_get_max_size(ft_strlen(grp->gr_name), \
				size->grpspace);
	}
	else
		size->grpspace = ft_get_max_size(ft_intlen(current->st_gid), \
				size->grpspace);
}

void				ft_lsdispsize(t_disp_size *size, t_obj *current)
{
	size->lnkspace = ft_get_max_size(ft_intlen(current->st_nlink), size->lnkspace);
	size->maj = ft_get_max_size(ft_intlen(major(current->st_rdev)), size->maj);
	size->min = ft_get_max_size(ft_intlen(minor(current->st_rdev)), size->min);
	size->size = ft_get_max_size(ft_intlen(current->st_size), size->size);
	size->total += current->st_blocks;
	ft_lsdisp_usrgrp_size(size, current);
}

t_disp_size			ft_lslongsize(t_arg arg, t_obj *files)
{
	t_obj			*current;
	t_disp_size		size;

	ft_memset(&size, 0, sizeof(t_disp_size));
	current = files;
	while (current)
	{
		if (!(arg.a == 0 && current->name[0] == '.'))
			ft_lsdispsize(&size, current);
		current = current->next;
	}
	return (size);
}
