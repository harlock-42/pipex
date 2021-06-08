/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:21:51 by tallaire          #+#    #+#             */
/*   Updated: 2021/05/27 18:21:55 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include "./libft.h"
# include "./color.h"
# include "./list.h"

char	**get_path(char **env);
char	**lst_to_tab(t_list *lst);
t_list	*get_arg(char **av);
void	exec_cmd(char **cmd, char **path);
void	*free_tab(char **tab);

#endif
