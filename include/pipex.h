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

# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "./libft.h"
# include "./color.h"
# include "./list.h"

char	**get_path(char **env);
int     exec(char **cmd, char **path);
int     pipex(t_list *arg, char **path);
t_list	*get_arg(char **av);

#endif
