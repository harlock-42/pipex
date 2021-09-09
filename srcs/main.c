/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:54:01 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/08 18:54:02 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	**path;
	t_list	*arg;
	int		ret;

	ret = 0;
	arg = NULL;
	if (argc != 5)
	{
		ft_putstr_fd("Error : wrong number of arguments\n", 2);
		return (1);
	}
	arg = get_arg(argv + 1);
	if (!arg)
		return (1);
	path = get_path(env);
	if (path == NULL)
		return ((int)lst_free(arg));
	ret = pipex(arg, path);
	lst_free(arg);
	free_tab(path);
	return (ret);
}
