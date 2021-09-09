/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:55:50 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/08 18:56:03 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*get_arg(char **av)
{
	t_list	*arg;
	int		i;

	arg = NULL;
	i = 0;
	while (av[i])
	{
		arg = lst_add_back(ft_strdup(av[i]), 0, arg);
		if (arg == NULL)
			return (lst_free(arg));
		++i;
	}
	return (arg);
}
