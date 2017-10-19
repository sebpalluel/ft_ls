/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsorganize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:54:44 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/19 16:16:26 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

void		ft_lsreverseorderobjs(t_obj **files)
{
	t_obj	*prev_file;
	t_obj	*current_file;
	t_obj	*next_file;

	prev_file = *files;
	current_file = NULL;
	while (prev_file)
	{
		next_file = current_file;
		current_file = prev_file;
		prev_file = prev_file->next;
		current_file->next = next_file;
	}
	*files = current_file;
}

static void	ft_lsorderobjs(t_obj **files, int (*f)(t_obj *obj1, t_obj *obj2))
{
	t_obj	*prev_file;
	t_obj	*next_file;

	prev_file = *files;
	while (prev_file)
	{
		next_file = prev_file->next;
		while (next_file)
		{
			if (f(prev_file, next_file) > 0)
				ft_lsswapobj(&prev_file, &next_file);
			next_file = next_file->next;
		}
		prev_file = prev_file->next;
	}
}

t_obj		*ft_lsorganizeobjs(t_obj *files, t_arg arg)
{
	t_obj	*objs;

	if (!files)
		return (NULL);
	objs = files;
	//if (arg.f == 0) // output is not sorted
	//{
		ft_lsorderobjs(&objs, ft_namecmp);
		(arg.t == 1 || arg.u == 1) ? ft_lsorderobjs(&objs, ft_timecmp) : NULL;
		arg.r == 1 ? ft_lsreverseorderobjs(&objs) : NULL;
	//}
	return (objs);
}
