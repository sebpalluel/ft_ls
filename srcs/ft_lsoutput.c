/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsoutput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:51:05 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/19 23:54:25 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

void	ft_lslongdisplayfile(t_arg arg, t_obj *current, t_disp_size size)
{
	ft_lsprintfilemode(current);
	ft_lsprintchmod(current);
	ft_lsprintint(current->st_nlink, size.lnkspace);
	if (arg.g == 0)
	{
		if (getpwuid(current->st_uid))
			ft_lsprintstr(getpwuid(current->st_uid)->pw_name, size.usrspace);
		else
			ft_lsprintstr(ft_itoa(current->st_uid), size.usrspace);
	}
	if (getgrgid(current->st_gid))
		ft_lsprintstr(getgrgid(current->st_gid)->gr_name, size.grpspace);
	else
		ft_lsprintstr(ft_itoa(current->st_gid), size.grpspace);
	if (S_ISCHR(current->st_mode) || S_ISBLK(current->st_mode))
		ft_lsprintmajmin(current, size);
	else
		ft_lsprintint(current->st_size, size.size);
	display_date(current->date);
	ft_color_mode(current->st_mode);
	ft_putendl(current->name);
	ft_putstr(ANSI_RESET);
}

void			ft_lslongdisplay(t_arg arg, t_obj *files, int fileordir)
{
	t_obj		*current;
	t_disp_size	size;

	current = files;
	size = ft_lslongsize(arg, files);
	if (fileordir)
	{
		ft_putstr("total ");
		ft_putnbr(size.total);
		ft_putchar('\n');
	}
	while (current)
	{
		if (!(arg.a == 0 && current->name[0] == '.'))
			ft_lslongdisplayfile(arg, current, size);
		current = current->next;
	}
}

void			ft_lsbasicdisplay(t_arg arg, t_obj *files)
{
	t_obj		*current;

	current = files;
	while (current)
	{
		if (!(arg.a == 0 && current->name[0] == '.'))
		{
			ft_color_mode(current->st_mode);
			ft_putendl(current->name);
			ft_putstr(ANSI_RESET);
		}
		current = current->next;
	}
}

void			ft_lsdisplay(t_arg arg, t_obj *files, int fileordir)
{
	t_obj		*current;

	current = files;
	current = ft_lsorganizeobjs(current, arg);
	(arg.l == 1) ? ft_lslongdisplay(arg, current, fileordir) : \
			ft_lsbasicdisplay(arg, current);
	//arg.R == 1 ? recursion(arg, current) : NULL;
	fileordir = 0;
}
