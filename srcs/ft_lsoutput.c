/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsoutput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:51:05 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/23 23:59:13 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

static void		ft_lslongdisplayfile2(t_obj *obj)
{
	ft_putstr(obj->final_time);
	ft_putchar(' ');
	ft_color_mode(obj->st_mode);
	ft_putstr(obj->name);
	if (S_ISLNK(obj->st_mode))
	{
		ft_putstr(ANSI_RESET);
		ft_putstr(" -> ");
		ft_putstr(obj->lnked_to);
	}
	ft_putchar('\n');
	ft_putstr(ANSI_RESET);
}

void			ft_lslongdisplayfile(t_arg arg, t_obj *obj, \
		t_disp_size size)
{
	ft_lsprintfilemode(obj);
	ft_lsprintchmod(obj);
	ft_lsprintint(obj->st_nlink, size.lnkspace);
	if (arg.g == 0)
	{
		if (getpwuid(obj->st_uid))
			ft_lsprintstr(getpwuid(obj->st_uid)->pw_name, size.usrspace);
		else
			ft_lsprintstr(ft_itoa(obj->st_uid), size.usrspace);
	}
	if (getgrgid(obj->st_gid))
		ft_lsprintstr(getgrgid(obj->st_gid)->gr_name, size.grpspace);
	else
		ft_lsprintstr(ft_itoa(obj->st_gid), size.grpspace);
	if (S_ISCHR(obj->st_mode) || S_ISBLK(obj->st_mode))
		ft_lsprintmajmin(obj, size);
	else
		ft_lsprintint(obj->st_size, size.size);
	ft_lslongdisplayfile2(obj);
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
		if (!(arg.a == 0 && arg.f == 0 && current->name[0] == '.'))
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
	arg.R == 1 ? ft_lsR(arg, current) : NULL;
	ft_lsdelobj(&files);
}
