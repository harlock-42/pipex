#include "pipex.h"

char ***free_cmd(char ***cmd)
{
    int     i;
    int     j;

    i = 0;
    while (cmd && cmd[i])
    {
        j = 0;
        while (cmd[i] && cmd[i][j])
        {
            free(cmd[i][j]);
            ++j;
        }
        free(cmd[i]);
        ++i;
    }
    free(cmd);
    return (NULL);
}

int check_cmd(char ***cmd)
{
    if (access(cmd[1][0], F_OK) == -1)
    {
        free_cmd(cmd);
        ft_putstr_fd("Error : Can't execute first command\n", 2);
        return (-1);
    }
    if (access(cmd[2][0], F_OK) == -1)
    {
        free_cmd(cmd);
        ft_putstr_fd("Error : Can't execute second command\n", 2);
        return (-1);
    }
    return (0);
}

void get_path_cmd(char **cmd, char **path)
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

int exec_cmd(char **cmd, char **path)
{
    get_path_cmd(cmd, path);
    if (cmd[0] == NULL)
    {
        printf("Aie aie aie\n");
        return (-1);
    }
    if (execve(cmd[0], cmd, NULL) == (-1))
    {
        perror("Shell");
        return (-1);
    }
    return (0);
}