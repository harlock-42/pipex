#include "pipex.h"

static	char	**get_var_path(char **env)
{
	char	**split;
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
			&& env[i][3] == 'H' && env[i][4] == '=')
			break ;
		++i;
	}
	split = ft_split(env[i] + 5, ':');
	if (!split)
		return (NULL);
	return (split);
}

char	**get_path(char **env)
{
	char	**str;

	str = get_var_path(env);
	if (!str)
		return (NULL);
	return (str);
}
