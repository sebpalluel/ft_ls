/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsprocess.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:56:17 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/22 19:36:37 by psebasti         ###   ########.fr       */
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

static void	ft_lsdir(t_arg arg, t_list *path, size_t mult_dir)
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

static void	ft_lsfile(t_arg arg, t_list *path)
{
	t_list	*current;
	t_obj	*files;

	current = path;
	files = NULL;
	while (current)
	{
		ft_lsgetfiles(&files, current->content, "", arg);
		current = current->next;
	}
	if (files)
		ft_lsdisplay(arg, files, 0);
}

static void	ft_lsdirorfile(t_list *current, t_list **file, t_list **directory)
{
	DIR		*dir;//

	if ((dir = opendir(current->content)) == NULL)
		errno != ENOTDIR ? ft_perror("ft_ls: ", current->content, 0) : \
				 ft_lstpushback(file, current->content, current->content_size);
	else
	{
		ft_lstpushback(directory, current->content, current->content_size);
		if (closedir(dir) == -1)
			ft_perror("ft_ls: ", current->content, 0);
	}
}

void		ft_lsprocess(t_arg arg, t_list *path, size_t mult_dir)
{
	t_list	*file;
	t_list	*directory;
	t_list	*current;

	file = NULL;
	current = path;
	directory = NULL;
	while (current)
	{
		ft_lsdirorfile(current, &file, &directory);
		current = current->next;
	}
	file ? ft_lsfile(arg, file) : NULL;
	(file && directory) ? ft_putchar('\n') : NULL;
	directory ? ft_lsdir(arg, directory, mult_dir) : NULL;
	ft_lstdel(&file, ft_lsdelpath);
	ft_lstdel(&directory, ft_lsdelpath);
}
