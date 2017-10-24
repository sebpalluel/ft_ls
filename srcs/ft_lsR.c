/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsR.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 01:39:04 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/24 02:26:55 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

void	ft_lsRprocess(t_arg arg, char *path)
{
	t_obj	*files;
	DIR		*dir;

	files = NULL;
	ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(":\n");
	if ((dir = opendir(path)) != NULL)
	{
		while (ft_lsgetobjsindir(&files, readdir(dir), \
					ft_strjoin(path, "/"), arg) != 0)
			;
		closedir(dir);
		if (files)
			ft_lsdisplay(arg, files, 1);
	}
	else
		ft_perror("ft_ls: ", path, 0);
}

void		ft_lsR(t_arg arg, t_obj *files)
{
	t_obj	*current;

	current = files;
	while (current)
	{
		if (current->name && current->path && \
				S_ISDIR(current->st_mode) && \
				ft_strcmp(".", current->name) && \
				ft_strcmp("..", current->name) && \
				!(arg.a == 0 && current->name[0] == '.'))
			ft_lsRprocess(arg, current->path);
		current = current->next;
	}
}
