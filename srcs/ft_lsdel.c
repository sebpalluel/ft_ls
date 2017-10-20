/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:34:09 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/20 16:56:16 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

void			ft_lsdelpath(void *path, size_t size)
{
	(void)size;
	free(path);
}

void			ft_lsdelobj(t_obj **alst)
{
	t_obj	*obj;
	t_obj	*obj_next;

	if (alst)
	{
		obj = *alst;
		while (obj)
		{
			obj_next = obj->next;
			free(obj->path);
			free(obj->name);
			free(obj);
			obj = obj_next;
		}
	}
	*alst = NULL;
}
