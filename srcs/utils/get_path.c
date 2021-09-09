/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:56:13 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/08 18:56:41 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	size_t	len_split(char **split)
{
	size_t	i;

	i = 0;
	while (split && split[i])
		++i;
	return (i);
}

static	char	**add_backslash(char **split)
{
	char	**new;
	int		i;
	size_t	size;

	i = 0;
	size = len_split(split);
	new = (char **)malloc(sizeof(char *) * size + 1);
	if (!new)
		return ((char **)free_tab(split));
	while (split && split[i])
	{
		new[i] = ft_strjoin(split[i], "/");
		++i;
	}
	free_tab(split);
	return (new);
}

static	char	**get_var_path(char **env)
{
	char	**split;
	int		i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
			&& env[i][3] == 'H' && env[i][4] == '=')
			break ;
		++i;
	}
	split = ft_split(env[i] + 5, ':');
	if (!split)
		return (NULL);
	split = add_backslash(split);
	if (!split)
		return (NULL);
	return (split);
}

char	**get_path(char **env)
{
	char	**str;

	str = get_var_path(env);
	if (!str)
		return (NULL);
	return (str);
}
