/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsgetinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:15:13 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/23 23:45:03 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

static t_obj	*ft_lsgetlink(t_obj *obj)
{
	int			link_len;
	char		*buf;

	if (!(buf = ft_strnew(1024)))
		return (NULL);
	if ((link_len = readlink(obj->path, buf, 1024)) == -1)
	{
		ft_perror("ft_ls: ", obj->name, 1);
		return (NULL);
	}
	obj->lnked_to = buf;
	return (obj);
}

static t_obj	*ft_newobj(char *name, char *path, t_arg arg)
{
	t_obj		*obj;
	struct stat	file_stat;

	obj = malloc(sizeof(t_obj));
	obj->name = ft_strdup(name);
	obj->path = ft_strjoin(path, name);
	if (lstat(obj->path, &file_stat) == -1)
	{
		ft_perror("ft_ls: ", obj->name, 1);
		return (NULL);
	}
	obj->date = (arg.u == 1 ? file_stat.st_atime : file_stat.st_mtime);
	obj->st_mode = file_stat.st_mode;
	obj->st_uid = file_stat.st_uid;
	obj->st_gid = file_stat.st_gid;
	obj->st_nlink = file_stat.st_nlink;
	obj->st_blocks = file_stat.st_blocks;
	obj->st_size = file_stat.st_size;
	obj->maj = major(file_stat.st_rdev);
	obj->min = minor(file_stat.st_rdev);
	if (S_ISLNK(obj->st_mode) && !(obj = ft_lsgetlink(obj)))
		return (NULL);
	obj->next = NULL;
	return (obj);
}

int				ft_lsgetobjsindir(t_obj **files, struct dirent *file, \
		char *path, t_arg arg)
{
	t_obj		*objs;

	objs = *files;
	if (!file)
	{
		if (path)
			free(path);
		return (0);
	}
	if (objs)
	{
		while (objs->next)
			objs = objs->next;
		objs->next = ft_newobj(file->d_name, path, arg);
	}
	else
		*files = ft_newobj(file->d_name, path, arg);
	free(path);
	return (1);
}

void			ft_lsgetfiles(t_obj **files, char *name, char *path, t_arg arg)
{
	t_obj		*objs;

	objs = *files;
	if (objs)
	{
		while (objs->next)
			objs = objs->next;
		objs->next = ft_newobj(name, path, arg);
	}
	else
		*files = ft_newobj(name, path, arg);
}
