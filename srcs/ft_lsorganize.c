/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsorganize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:54:44 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/18 20:07:20 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

t_obj		*ft_lsorganizeobjs(t_obj *list, t_arg arg)
{
	t_obj	*new;

	if (!list)
		return (NULL);
	new = list;
	//if (arg.f == 0) // output is not sorted
	//{
		sort(&new, cmp_alpha);
		(arg.t == 1 || arg.u == 1) ? sort(&new, cmp_time) : NULL;
		arg.r == 1 ? reversesort(&new) : NULL;
	//}
	return (new);
}
