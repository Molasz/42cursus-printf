#include "ft_printf.h"

int ft_putstr(char *arg, int *flags)
{
    char    *res;
    char    justifyc;
    int     len;

    res = arg;
    if (flags[4])
        res = ft_substr(res, 0, flags[4]);
    if (!res)
        return (-1);
    if (flags[3])
        res = ft_strjustify(res, flags[3], flags[0], flags[1]);
    return (write(1, res, ft_strlen(res)));
}