#include "pipex.h"

static void get_path_cmd(char **cmd, char **path)
{
    int     i;
    char    *bin;

    i = 0;
    if (cmd[0][0] == '/' || (cmd[0][0] == '.' && cmd[0][1] == '/'))
        return ;
    while (path && path[i])
    {
        bin = ft_calloc(sizeof(char *), ft_strlen(path[i])
                + ft_strlen(cmd[0]) + 2);
        if (bin == NULL)
            return ;
        ft_strcat(bin, path[i]);
        ft_strcat(bin, "/");
        ft_strcat(bin, cmd[0]);
        if (access(bin, F_OK) == 0)
            break ;
        free(bin);
        bin = NULL;
        ++i;
    }
    free(cmd[0]);
    cmd[0] = bin;
}

int exec(char **cmd, char **path)
{
    pid_t   pid;
    int     status;

    status = 0;
    get_path_cmd(cmd, path);
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
        if (execve(cmd[0], cmd, NULL) == (-1))
            perror("Shell");
        exit(EXIT_FAILURE);
    }
    (void)path;
    return (0);
}