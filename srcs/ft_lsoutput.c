/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsoutput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:51:05 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/19 22:34:19 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

//void	ft_lslongdisplayfile(t_arg arg, t_obj *cur, t_size size)
//{
//	print_access(cur);
//	print_int(cur->st_nlink, size.linkspace);
//	if (arg.g == 0)
//	{
//		if (getpwuid(cur->st_uid))
//			print_str(getpwuid(cur->st_uid)->pw_name, size.userspace);
//		else
//			print_str(ft_itoa(cur->st_uid), size.userspace);
//	}
//	if (getgrgid(cur->st_gid))
//		print_str(getgrgid(cur->st_gid)->gr_name, size.groupspace);
//	else
//		print_str(ft_itoa(cur->st_gid), size.groupspace);
//	if (S_ISCHR(cur->st_mode) || S_ISBLK(cur->st_mode))
//		print_majmin(cur, size);
//	else
//		print_int(cur->st_size, size.size);
//	display_date(cur->date);
//	ft_color(cur->st_mode);
//	ft_putendl(cur->name);
//	ft_putstr(C_NONE);
//}

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
		//if (!(arg.a == 0 && current->name[0] == '.'))
		//	ft_lslongdisplayfile(arg, current, size);
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
