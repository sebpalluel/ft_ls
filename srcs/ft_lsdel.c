/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:34:09 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/20 16:07:41 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

void			ft_lsdelpath(void *path, size_t size)
{
	(void)size;
	printf("path : %s\n", (char*)path);
	free(path);
}

void			ft_lsdelobj(t_obj *obj, size_t size)
{
	(void)size;
	printf("obj->path : %s\n", (char*)obj->path);
	free(obj->path);
}
