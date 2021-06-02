#include "pipex.h"

static	t_list	*add_split(char *av, t_list *arg)
{
	int	i;
	char	**split;

	i = 0;
	split = ft_split(av, ' ');
	if (split == NULL)
		return (lst_free(arg));
	while (split[i])
	{
		arg = lst_add_back(ft_strdup(split[i]), 0, arg);
		if (arg == NULL)
			return (lst_free(arg));
		++i;
	}
	return (arg);
}

t_list	*get_arg(char **av)
{
	t_list	*arg;
	int	i;

	arg = NULL;
	i = 0;
	while (av[i])
	{
		if (c_is_str(' ', av[i]) == NO)
		{
			arg = lst_add_back(ft_strdup(av[i]), 0, arg);
			if (arg == NULL)
				return (lst_free(arg));
		}
		else
		{
			arg = add_split(av[i], arg);
			if (arg == NULL)
				return (NULL);
		}
		++i;
	}
	return (arg);
}
