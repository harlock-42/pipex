#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_list	*arg;

	arg = NULL;
	(void)env;
	if (argc <= 1)
		return (0);
	arg = get_arg(argv + 1);
	lst_print(arg);
	return (0);
}
