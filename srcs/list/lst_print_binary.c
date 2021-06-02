/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:25:09 by tallaire          #+#    #+#             */
/*   Updated: 2021/05/27 18:25:10 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	lst_print_binary(t_list *lst)
{
	while (lst)
	{
		print_binary(lst->index, 1);
		lst = lst->next;
	}
	ft_printf("%sNULL%s\n", YELLOW, NC);
}
