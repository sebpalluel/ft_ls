/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:03:39 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/23 23:43:35 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

int			ft_namecmp(t_obj *obj1, t_obj *obj2)
{
	return (ft_strcmp(obj1->name, obj2->name));
}

int			ft_timecmp(t_obj *obj1, t_obj *obj2)
{
	//int		time_diff;

	//if (obj1->date.tm_mon)
	if (obj1->date < obj2->date)
	{
	//	printf("obj1 name %s, date %ld, obj2 name %s, date %ld time_diff %d\n", \
	//			obj1->name, obj1->date, obj2->name, obj2->date, time_diff);
		return (1);
	}
	else
		return (0);
}

void		ft_lscpyobj(t_obj **objs, t_obj *to_cpy)
{
	(*objs)->name = to_cpy->name;
	(*objs)->path = to_cpy->path;
	(*objs)->date = to_cpy->date;
	(*objs)->st_mode = to_cpy->st_mode;
	(*objs)->st_uid = to_cpy->st_uid;
	(*objs)->st_gid = to_cpy->st_gid;
	(*objs)->st_nlink = to_cpy->st_nlink;
	(*objs)->st_blocks = to_cpy->st_blocks;
	(*objs)->st_size = to_cpy->st_size;
	(*objs)->not_a_dir = to_cpy->not_a_dir;
	(*objs)->maj = to_cpy->maj;
	(*objs)->min = to_cpy->min;
	(*objs)->lnked_to = to_cpy->lnked_to;
}

void		ft_lsswapobj(t_obj **a, t_obj **b)
{
	t_obj	tmp;

	tmp = **a;
	ft_lscpyobj(a, *b);
	ft_lscpyobj(b, &tmp);
}

void		ft_color_mode(mode_t mode)
{
	S_ISDIR(mode) ? ft_putstr(ANSI_BLUE) : NULL;
	S_ISCHR(mode) ? ft_putstr(ANSI_YELLOW) : NULL;
	S_ISBLK(mode) ? ft_putstr(ANSI_RED) : NULL;
	S_ISREG(mode) ? ft_putstr(ANSI_WHITE) : NULL;
	S_ISFIFO(mode) ? ft_putstr(ANSI_LIGHT_GREEN) : NULL;
	S_ISSOCK(mode) ? ft_putstr(ANSI_GREEN) : NULL;
	S_ISLNK(mode) ? ft_putstr(ANSI_MAGENTA) : NULL;
}
