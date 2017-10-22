/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 22:53:07 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/22 18:15:30 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

void		ft_lsprintchmod(t_obj *obj)
{
	ft_putchar((obj->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((obj->st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((obj->st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((obj->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((obj->st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((obj->st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((obj->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((obj->st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((obj->st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("  ");
}

void		ft_lsprintfilemode(t_obj *obj)
{
	ft_putchar((S_ISFIFO(obj->st_mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(obj->st_mode)) ? 'c' : '\0');
	ft_putchar((S_ISDIR(obj->st_mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(obj->st_mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(obj->st_mode)) ? '-' : '\0');
	ft_putchar((S_ISLNK(obj->st_mode)) ? 'l' : '\0');
	ft_putchar((S_ISSOCK(obj->st_mode)) ? 's' : '\0');
}

void		ft_lsprintint(int num, int space)
{
	int		c;

	c = space - ft_intlen(num);
	while (c > 0)
	{
		ft_putchar(' ');
		c--;
	}
	ft_putnbr(num);
	ft_putstr(" ");
}

void		ft_lsprintstr(char *str, int space)
{
	int		c;

	c = space - ft_strlen(str);
	ft_putstr(str);
	while (c > 0)
	{
		ft_putchar(' ');
		c--;
	}
	ft_putstr("  ");
}

void		ft_lsprintmajmin(t_obj *file, t_disp_size size)
{
	int		min;
	int		maj;

	min = ft_intlen(file->min);
	maj = ft_intlen(file->maj);
	while (maj < size.maj)
	{
		ft_putchar(' ');
		size.maj--;
	}
	ft_putnbr(file->maj);
	ft_putstr(", ");
	while (min < size.min)
	{
		ft_putchar(' ');
		size.min--;
	}
	ft_putnbr(file->min);
	ft_putchar(' ');
}
