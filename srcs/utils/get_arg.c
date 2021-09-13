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
	char	*buff;
	t_list	*arg;
	int		i;

	arg = NULL;
	i = 0;
	buff = NULL;
	while (av[i])
	{
		buff = ft_strdup(av[i]);
		if (buff == NULL)
			return (lst_free(arg));
		arg = lst_add_back(buff, 0, arg);
		if (arg == NULL)
		{
			free(buff);
			return (lst_free(arg));
		}
		++i;
	}
	return (arg);
}
