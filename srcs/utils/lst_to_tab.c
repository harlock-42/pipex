/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:56:51 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/08 18:56:59 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**lst_to_tab(t_list *lst)
{
	t_list	*tmp;
	char	**tab;
	size_t	size;
	int		i;

	tab = NULL;
	i = 0;
	size = lst_size(lst);
	tab = (char **)malloc(sizeof(char *) * size + 1);
	if (tab == NULL)
		return (NULL);
	tmp = lst;
	while (tmp)
	{
		tab[i] = ft_strdup(tmp->str);
		if (tab[i] == NULL)
			return ((char **)free_tab(tab));
		++i;
		tmp = tmp->next;
	}
	return (tab);
}
