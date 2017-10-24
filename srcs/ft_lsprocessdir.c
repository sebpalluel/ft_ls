/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsprocessdir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 18:57:07 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/24 01:55:20 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

static void	ft_dirlistprocess(t_arg arg, t_obj *dirlist, size_t mult_dir)
{
	DIR		*dir;
	t_obj	*files;
	char	*tmp;

	files = NULL;
	tmp = NULL;
	dir = opendir(dirlist->name);
	while (ft_lsgetobjsindir(&files, readdir(dir), \
				ft_strjoin(dirlist->path, "/"), arg) != 0)
		;
	closedir(dir);
	if (files)
	{
		if (mult_dir)
		{
			ft_putendl((tmp = ft_strjoin(dirlist->name, ":")));
			free(tmp);
		}
		ft_lsdisplay(arg, files, 1);
	}
}

static void	ft_lsinsidedirs(t_arg arg, t_obj *dirlist, size_t mult_dir)
{
	t_obj	*head;

	head = dirlist;
	while (dirlist)
	{
		ft_dirlistprocess(arg, dirlist, mult_dir);
		dirlist->next != NULL ? ft_putchar('\n') : NULL;
		dirlist = dirlist->next;
	}
	ft_lsdelobj(&head);
}

void		ft_lsdir(t_arg arg, t_list *path, size_t mult_dir)
{
	t_list	*current;
	t_obj	*dirs;

	current = path;
	dirs = NULL;
	while (current)
	{
		ft_lsgetfiles(&dirs, current->content, "", arg);
		current = current->next;
	}
	dirs = ft_lsorganizeobjs(dirs, arg);
	ft_lsinsidedirs(arg, dirs, mult_dir);
}
