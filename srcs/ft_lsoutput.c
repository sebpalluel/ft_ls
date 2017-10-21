/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsoutput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:51:05 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/21 20:32:26 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

static void		ft_lsdisplaytime(time_t date, char *file_time, char *base_time)
{
	char		*base_time_alt;
	char		*final_time;
	char		*tmp;
	long int	current_time;

	current_time = time(0);
	if ((date > current_time) || (date < (current_time - SIXMONTHSINSEC)))
	{
		base_time_alt = ft_strjoin(base_time, " ");
		tmp = ft_strsub(file_time, 19, 5);
		ft_putstr(final_time = ft_strjoin(base_time_alt, tmp));
		free(base_time_alt);
	}
	else
	{
		tmp = ft_strsub(file_time, 10, 6);
		ft_putstr(final_time = ft_strjoin(base_time, tmp));
	}
	ft_putchar(' ');
	free(final_time);
	free(tmp);
}

static void		ft_lsgivetime(time_t date)
{
	char		*base_time;
	char		*file_time;

	file_time = ft_strdup(ctime(&date));
	base_time = ft_strsub(file_time, 4, 6);
	ft_lsdisplaytime(date, file_time, base_time);
	free(file_time);
	free(base_time);
}

void			ft_lslongdisplayfile(t_arg arg, t_obj *current, \
		t_disp_size size)
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
	{
		ft_lsprintmajmin(current, size);
	}
	else
		ft_lsprintint(current->st_size, size.size);
	ft_lsgivetime(current->date);
	ft_color_mode(current->st_mode);
	ft_putstr(current->name);
	if (S_ISLNK(current->st_mode))
	{
		ft_putstr(ANSI_RESET);
		ft_putstr(" -> ");
		ft_putstr(current->lnked_to);
	}
	ft_putchar('\n');
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
	arg.R == 1 ? ft_lsR(arg, current) : NULL;
	ft_lsdelobj(&files);
}
