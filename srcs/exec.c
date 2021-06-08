#include "pipex.h"

static	char	*get_exec(char *cmd, char **path)
{
	int	i;
	char	*path_name;
	int	ret;
	char	*tmp;

	i = 0;
	tmp = NULL;
	path_name = NULL;
	ret = (-1);
	while (path[i] && ret == (-1))
	{
		if (path_name)
			free(path_name);
		path_name = ft_strjoin(path[i], cmd);
		if (!path_name)
			return (NULL);
		ret = open(path_name, O_RDONLY);
		++i;
	}
	return (path_name);
}

static	int	ft_execve(char **cmd, char **path)
{
	int	i;
	int	ret;
	char	*exec;

	exec = get_exec(cmd[0], path);
	if (exec == NULL)
		return (-1);
	i = 0;
	ret = (-1);
	execve(exec, cmd, NULL);
	return (-1);
}

void	exec_cmd(char **cmd, char **path)
{
	pid_t	pid;
	int	status;

	pid = 0;
	status = 0;
	pid = fork();
	if (pid == (-1))
		perror("fork");
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (ft_execve(cmd, path) == (-1))
			perror("Shell");
		exit(EXIT_FAILURE);
	}
}
