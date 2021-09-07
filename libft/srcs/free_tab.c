#include "../includes/libft.h"

void	**free_tab(char **str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		str[i] = NULL;
		++i;
	}
	free(str);
	return (NULL);
}
