/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:25:00 by tallaire          #+#    #+#             */
/*   Updated: 2021/05/27 18:25:02 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	lst_print(t_list *lst)
{
	while (lst)
	{
		ft_printf("%s\n", lst->str);
		lst = lst->next;
	}
	ft_printf("%sNULL%s\n", YELLOW, NC);
}
