#include "pipex.h"

int pipex(t_list *arg, char **path)
{
	char	**cmd;

	cmd = ft_split(arg->str, ' ');
	exec(cmd, path);
	free_tab(cmd);
	return (0);
}