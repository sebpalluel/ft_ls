/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:37:17 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/20 01:34:31 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

static void		ft_error_arg(char arg)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(arg, 2);
	ft_putstr_fd("\nusage: ft_ls [-lRartg] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

static void		ft_select_arg(t_arg *arg, char c_arg)
{
	if (!arg->l && c_arg == 'l')
		arg->l = 1;
	if (!arg->R && c_arg == 'R')
		arg->R = 1;
	if (!arg->a && c_arg == 'a')
		arg->a = 1;
	if (!arg->r && c_arg == 'r')
		arg->r = 1;
	if (!arg->t && c_arg == 't')
		arg->t = 1;
	if (!arg->g && c_arg == 'g')
		arg->g = 1;
}

static void		ft_get_arg(t_arg *arg, char *curr_arg)
{
	size_t		i;

	i = 0;
	while (curr_arg[++i])
	{
		if (ft_stroneof(curr_arg[i], "1lRartug") != ERROR || \
				(curr_arg[1] == '-' && !curr_arg[2]))
			ft_select_arg(arg, curr_arg[i]);
		else
			ft_error_arg(curr_arg[i]);
	}
}

static void		ft_parse_arg(int argc, char **argv, t_arg *arg, t_list **list)
{
	int			nb_arg;
	char		*curr_arg;

	nb_arg = -1;
	while (++nb_arg < (argc - 1))
	{
		curr_arg = argv[nb_arg + 1];
		if (curr_arg && curr_arg[0] == '-' && \
				curr_arg[1] != '\0')
			ft_get_arg(arg, curr_arg);
		else
			ft_lstpushback(list, curr_arg, ft_strlen(curr_arg));
	}
}

int				main(int argc, char **argv)
{
	t_arg		arg;
	t_list		*list;

	list = NULL;
	ft_memset(&arg, 0, sizeof(t_arg));
	if (argc > 1)
		ft_parse_arg(argc, argv, &arg, &list);
	if (list == NULL)
		list = ft_lstnew(".", 1);
	ft_lsprocess(arg, list, list->next != NULL ? 1 : 0);
	return (0);
}
