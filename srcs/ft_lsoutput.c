/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsoutput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:51:05 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/18 20:05:32 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

void		ft_lsdisplay(t_arg arg, t_obj *files, int fileordir)
{
	t_obj	*current;

	current = files;
	current = ft_lsorganizeobjs(current, arg);
	(arg.l == 1) ? ls_long(arg, current, fileordir) : ls_simple(arg, current);
	arg.R == 1 ? recursion(arg, current) : NULL;
}
