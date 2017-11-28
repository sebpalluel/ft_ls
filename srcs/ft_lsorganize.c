/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsorganize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:54:44 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/25 14:02:27 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_lsreverseorderobjs(t_obj **files)
{
	t_obj	*prev_file;
	t_obj	*next_file;

	prev_file = *files;
	while (prev_file)
	{
		next_file = prev_file->next;
		while (next_file)
		{
			ft_lsswapobj(&prev_file, &next_file);
			next_file = next_file->next;
		}
		prev_file = prev_file->next;
	}
}

static void	ft_lsbubblesortobjs(t_obj **files, \
		int (*f)(t_obj *obj1, t_obj *obj2))
{
	t_obj	*obj;
	t_obj	*lptr;
	size_t	swapped;

	lptr = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		obj = *files;
		while (obj->next != lptr)
		{
			if (f(obj, obj->next) > 0)
			{
				ft_lsswapobj(&obj, &obj->next);
				swapped = 1;
			}
			obj = obj->next;
		}
		lptr = obj;
	}
}

t_obj		*ft_lsorganizeobjs(t_obj *files, t_arg arg)
{
	t_obj	*objs;

	if (!files)
		return (NULL);
	objs = files;
	if (arg.f == 0)
	{
		ft_lsbubblesortobjs(&objs, ft_namecmp);
		if (arg.t == 1)
			ft_lsbubblesortobjs(&objs, ft_timecmp);
		arg.r == 1 ? ft_lsreverseorderobjs(&objs) : NULL;
	}
	return (objs);
}
