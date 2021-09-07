#include "../includes/libft.h"

char    *ft_strcat(char *dst, const char *src)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (dst[j])
        ++j;
    while (src[i])
    {
        dst[j + i] = src[i];
        ++i;
    }
    dst[j + i] = '\0';
    return (dst);
}