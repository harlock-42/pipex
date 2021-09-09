/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:43:26 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/08 18:43:27 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	**free_tab(char **str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		str[i] = NULL;
		++i;
	}
	free(str);
	return (NULL);
}
