#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int     pipe_fd[2];
    pid_t   cpid;
    char    buf;
    char    *cmd[] = {"wc", NULL};
    char    *cmd1[] = {"cat", NULL};
    int     fd_in;
    int     fd_out;

    if (pipe(pipe_fd) == -1)
        return (2);
    if ((fd_in = open(argv[1], O_RDONLY)) == -1)
        return (4);
    if ((fd_out = open(argv[2], O_WRONLY)) == -1)
        return (5);
    dup2(fd_in, 0);
    cpid = fork();
    if (cpid == -1)
        return (3);
    if (cpid == 0)
    {
        close(pipe_fd[0]);
        dup2(pipe_fd[1], 1);
        close(pipe_fd[1]);
        execvp(cmd1[0], cmd1);
    }
    cpid = fork();
    dup2(fd_out, 1);
    if (cpid == 0)
    {
        close(pipe_fd[1]);
        dup2(pipe_fd[0], 0);
        close(pipe_fd[0]);
        execvp(cmd[0], cmd);
    }
    return (0);
}