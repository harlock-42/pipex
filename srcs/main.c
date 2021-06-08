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
		return (0);
	path = get_path(env);
	if (!path)
		return ((int)lst_free(arg));
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
