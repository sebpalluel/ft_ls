/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:03:39 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/19 16:06:17 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

int			ft_namecmp(t_obj *obj1, t_obj *obj2)
{
	return (ft_strcmp(obj1->name, obj2->name));
}

int			ft_timecmp(t_obj *obj1, t_obj *obj2)
{
	return (obj1->date < obj2->date);
}

void		ft_lscpyobj(t_obj **objs, t_obj *to_cpy)
{
	(*objs)->name = to_cpy->name;
	(*objs)->path = to_cpy->path;
	(*objs)->date = to_cpy->date;
	(*objs)->st_mode = to_cpy->st_mode;
	(*objs)->st_nlink = to_cpy->st_nlink;
	(*objs)->st_uid = to_cpy->st_uid;
	(*objs)->st_gid = to_cpy->st_gid;
	(*objs)->st_size = to_cpy->st_size;
	(*objs)->st_blocks = to_cpy->st_blocks;
}

void		ft_lsswapobj(t_obj **a, t_obj **b)
{
	t_obj	tmp;

	tmp = **a;
	ft_lscpyobj(a, *b);
	ft_lscpyobj(b, &tmp);
}
