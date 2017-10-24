/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsoutputtime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 17:34:33 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/24 00:12:14 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

static char		*ft_lsgetfinaltime(time_t date, char *file_time, \
		char *base_time)
{
	char		*base_time_alt;
	char		*tmp;
	long int	current_time;
	char		*final_time;

	current_time = time(0);
	if ((date > current_time) || (date < (current_time - SIXMONTHSINSEC)))
	{
		base_time_alt = ft_strjoin(base_time, " ");
		tmp = ft_strsub(file_time, 19, 5);
		final_time = ft_strjoin(base_time_alt, tmp);
		free(base_time_alt);
	}
	else
	{
		tmp = ft_strsub(file_time, 10, 6);
		final_time = ft_strjoin(base_time, tmp);
	}
	free(tmp);
	return (final_time);
}

char			*ft_lsgivetime(time_t date)
{
	char		*base_time;
	char		*file_time;
	char		*final_time;

	file_time = ft_strdup(ctime(&date));
	base_time = ft_strsub(file_time, 4, 6);
	final_time = ft_lsgetfinaltime(date, file_time, base_time);
	free(file_time);
	free(base_time);
	return (final_time);
}


