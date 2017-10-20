/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:34:09 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/20 15:51:38 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

void			ft_lsdelpath(void *path, size_t size)
{
	(void)size;
	printf("path : %s\n", (char*)path);
	free(path);
}


