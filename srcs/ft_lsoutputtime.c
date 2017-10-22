/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsoutputtime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 17:34:33 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/22 17:36:04 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

static void		ft_lsdisplaytime(time_t date, char *file_time, char *base_time)
{
	char		*base_time_alt;
	char		*final_time;
	char		*tmp;
	long int	current_time;

	current_time = time(0);
	if ((date > current_time) || (date < (current_time - SIXMONTHSINSEC)))
	{
		base_time_alt = ft_strjoin(base_time, " ");
		tmp = ft_strsub(file_time, 19, 5);
		ft_putstr(final_time = ft_strjoin(base_time_alt, tmp));
		free(base_time_alt);
	}
	else
	{
		tmp = ft_strsub(file_time, 10, 6);
		ft_putstr(final_time = ft_strjoin(base_time, tmp));
	}
	ft_putchar(' ');
	free(final_time);
	free(tmp);
}

void			ft_lsgivetime(time_t date)
{
	char		*base_time;
	char		*file_time;

	file_time = ft_strdup(ctime(&date));
	base_time = ft_strsub(file_time, 4, 6);
	ft_lsdisplaytime(date, file_time, base_time);
	free(file_time);
	free(base_time);
}
