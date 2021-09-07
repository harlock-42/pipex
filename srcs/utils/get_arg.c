#include "pipex.h"

t_list	*get_arg(char **av)
{
	t_list	*arg;
	int	i;

	arg = NULL;
	i = 0;
	while (av[i])
	{
		arg = lst_add_back(ft_strdup(av[i]), 0, arg);
		if (arg == NULL)
			return (lst_free(arg));
		++i;
	}
	return (arg);
}
