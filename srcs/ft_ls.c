/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:37:17 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/18 15:52:23 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

int		main(int argc, char **argv)
{
	t_arg	arg;
	t_list	*lst;

	lst = NULL;
	ft_memset(&arg, 0, sizeof(t_arg));
	if (argc > 1)
		get_param(argc - 1, argv, &arg, &lst);
	if (lst == NULL)
		lst = ft_lstnew(".", ft_strlen("."));
	core(arg, lst, lst->next != NULL ? 1 : 0);
	return (0);
}
