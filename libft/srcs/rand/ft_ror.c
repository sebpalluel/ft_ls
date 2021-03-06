/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 18:36:33 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/02 19:28:11 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_ror(const unsigned int value, int shift)
{
	if ((shift &= sizeof(value) * 8 - 1) == 0)
		return (value);
	return (value >> shift) | (value << (sizeof(value) * 8 - shift));
}
