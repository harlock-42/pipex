#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_list	*arg;
	char	r/share/applications/exo-web-browser.desktop' path;

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
	lst_print(arg);
	return (0);
}
