/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsprocess.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:56:17 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/20 01:35:23 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

static void	ft_lsinsidedirs(t_arg arg, t_obj *dirlist, int multidir)
{
	DIR		*dir;
	t_obj	*files;
	int		first;

	first = 0;
	files = NULL;
	while (dirlist)
	{
		dir = opendir(dirlist->name);
		while (ft_lsgetfilesindir(&files, readdir(dir), \
			ft_strjoin(dirlist->path, "/"), arg) != 0)
			;
		closedir(dir);
		if (files)
		{
			first == 1 ? ft_putchar('\n') : NULL;
			multidir ? ft_putendl(ft_strjoin(dirlist->name, ":")) : NULL;
			first = 1;
			ft_lsdisplay(arg, files, 1);
		}
		files = NULL;
		dirlist = dirlist->next;
	}
}

static void	ft_lsdir(t_arg arg, t_list *list, int end_dir)
{
	t_list	*current;
	t_obj	*dirs;

	current = list;
	dirs = NULL;
	while (current)
	{
		ft_lsgetfiles(&dirs, current->content, "", arg);
		current = current->next;
	}
	dirs = ft_lsorganizeobjs(dirs, arg);
	ft_lsinsidedirs(arg, dirs, end_dir);
}

static void	ft_lsfile(t_arg arg, t_list *list)
{
	t_list	*current;
	t_obj	*files;

	current = list;
	files = NULL;
	while (current)
	{
		ft_lsgetfiles(&files, current->content, "", arg);
		current = current->next;
	}
	if (files)
		ft_lsdisplay(arg, files, 0);
}

void		ft_lsprocess(t_arg arg, t_list *list, int end_dir)
{
	DIR		*dir;
	t_list	*file;
	t_list	*directory;
	t_list	*current;

	file = NULL;
	directory = NULL;
	current = list;
	while (current)
	{
		if ((dir = opendir(current->content)) == NULL)
			errno != ENOTDIR ? ft_perror("ft_ls: ", current->content, 0) : \
				ft_lstpushback(&file, current->content, current->content_size);
		else
		{
			ft_lstpushback(&directory, current->content, current->content_size);
			if (closedir(dir) == -1)
				ft_perror("ft_ls: ", current->content, 0);
		}
		current = current->next;
	}
	file ? ft_lsfile(arg, file) : NULL;
	(file && directory) ? ft_putchar('\n') : NULL;
	directory ? ft_lsdir(arg, directory, end_dir) : NULL;
}
