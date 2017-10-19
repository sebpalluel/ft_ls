/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:37:17 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/19 15:11:57 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

static void	ft_error_arg(char arg)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(arg, 2);
	ft_putstr_fd("\nusage: ft_ls [-lRart] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

static void	ft_get_arg(t_arg *arg, char *curr_arg)
{
	size_t	i;

	i = 0;
	while (curr_arg[++i])
	{
		if (ft_stroneof(curr_arg[i], "1lRartu") != ERROR || \
				(curr_arg[1] == '-' && !curr_arg[2]))
		{
			arg->l = (curr_arg[i] == 'l' ? 1 : 0);
			arg->R = (curr_arg[i] == 'R' ? 1 : 0);
			arg->a = (curr_arg[i] == 'a' ? 1 : 0);
			arg->r = (curr_arg[i] == 'r' ? 1 : 0);
			arg->t = (curr_arg[i] == 't' ? 1 : 0);
		}
		else
			ft_error_arg(curr_arg[i]);
	}
}

static void	ft_parse_arg(int argc, char **argv, t_arg *arg, t_list **lst)
{
	int		nb_arg;
	char	*curr_arg;

	nb_arg = -1;
	while (++nb_arg < (argc - 1))
	{
		curr_arg = argv[nb_arg + 1];
		if (curr_arg && curr_arg[0] == '-' && \
				curr_arg[1] != '\0')
			ft_get_arg(arg, curr_arg);
		else
			ft_lstpushback(lst, curr_arg, ft_strlen(curr_arg));
	}
}

int			main(int argc, char **argv)
{
	t_arg	arg;
	t_list	*lst;

	lst = NULL;
	ft_memset(&arg, 0, sizeof(t_arg));
	if (argc > 1)
		ft_parse_arg(argc, argv, &arg, &lst);
	if (lst == NULL)
		lst = ft_lstnew(".", 1);
	ft_ls_process(arg, lst, lst->next != NULL ? 1 : 0);
	return (0);
}
