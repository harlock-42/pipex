#include "pipex.h"

void	*free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		++i;
	}
	if (tab)
		free(tab);
	return (NULL);
}
