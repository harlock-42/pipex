#include "pipex.h"

static	char	***get_cmd(char ***cmd, t_list *arg, char **path)
{
	cmd[0] = ft_split(arg->str, ' ');
	cmd[1] = ft_split(arg->next->str, ' ');
	cmd[2] = ft_split(arg->next->next->str, ' ');
	cmd[3] = ft_split(arg->next->next->next->str, ' ');
	if (cmd[0] == NULL || cmd[1] == NULL || cmd[2] == NULL || cmd[3] == NULL)
	{
		free_cmd(cmd);
		return (NULL);
	}
	if (cmd[1][0] == '\0' || cmd[1][0] == '\0')
	{
		ft_putstr_fd("Error : At least one of your command is empty\n", 2);
		free_cmd(cmd);
		return (NULL);
	}
	get_path_cmd(cmd[1], path);
	get_path_cmd(cmd[2], path);
	return (cmd);
}

static	int	do_child1_process(char **cmd, int *pipe_fd, char **path)
{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		if (exec_cmd(cmd, path))
			return (-1);
		return (0);
}

static	int	give_me_a_fork(char ***cmd, int *pipe_fd, int fd_out, char ** path)
{
	pid_t	cpid;

	cpid = fork();
	if (cpid == -1)
		return (-1);
	if (cpid == 0)
	{
		do_child1_process(cmd[1], pipe_fd, path);
	}
	wait(NULL);
	cpid = fork();
	dup2(fd_out, 1);
	if (cpid == -1)
		return (-1);
	if (cpid == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		if (exec_cmd(cmd[2], path))
			exit(1);
	}
	return (0);
}

static	int	execution(char ***cmd, char **path)
{
	int		pipe_fd[2];
	int		fd_in;
	int		fd_out;

	if (pipe(pipe_fd) == -1)
		return (-1);
	fd_in = open(cmd[0][0], O_RDONLY);
	if (fd_in == -1)
	{
		ft_putstr_fd("Can't open first file\n", 2);
		return (-1);
	}
	fd_out = open(cmd[3][0], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fd_out == -1)
	{
		ft_putstr_fd("Can't create or open second file\n", 2);
		return (-1);
	}
	dup2(fd_in, 0);
	if (give_me_a_fork(cmd, pipe_fd, fd_out, path))
		return (-1);
	return (0);
}

int pipex(t_list *arg, char **path)
{
	char	***cmd;

	cmd = (char ***)ft_calloc(lst_size(arg) + 1, sizeof(char **));
	if (cmd == NULL)
		return (-1);
	cmd = get_cmd(cmd, arg, path);
	if (cmd == NULL)
		return (-1);
	if (check_cmd(cmd))
		return (-1);
	if (execution(cmd, path))
	{
		free_cmd(cmd);
		return (-1);
	}
	free_cmd(cmd);
	return (0);
}