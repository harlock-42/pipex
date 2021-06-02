/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:18:25 by tallaire          #+#    #+#             */
/*   Updated: 2021/05/27 18:18:27 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	t_list	*first_link(t_list *list, char *str, int nb)
{
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->str = str;
	list->nb = nb;
	list->next = NULL;
	return (list);
	return (list);
}

t_list	*lst_add_back(char *str, int nb, t_list *list)
{
	t_list	*new;
	t_list	*tmp;

	tmp = list;
	if (list == NULL)
		return (first_link(list, str, nb));
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		if (str != NULL)
			free(str);
		return (NULL);
	}
	new->str = str;
	new->nb = nb;
	new->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}
