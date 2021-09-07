#include "pipex.h"



int	main(int argc, char **argv, char **env)
{
	(void)env;
	t_list	*arg;
	char	**path;

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
	return (0);
}
