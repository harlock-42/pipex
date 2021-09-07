#include "pipex.h"



int	main(int argc, char **argv, char **env)
{
	char	**path;
	char	**cmd;
	t_list	*arg;

	arg = NULL;
	(void)env;
	if (argc <= 1)
		return (0);
	arg = get_arg(argv + 1);
	if (!arg)
		return (1);
	path = get_path(env);
	if (path == NULL)
		return ((int)lst_free(arg));
	if (pipex(arg, path))
		return (-1);
	lst_free(arg);
	free_tab(path);
	cmd = lst_to_tab(arg);
	if (!cmd)
	{
		lst_free(arg);
		free_tab(cmd);
		return (0);
	}
	exec_cmd(cmd, path);
	return (0);
}
