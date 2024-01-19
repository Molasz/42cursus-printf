#include "ft_printf.h"

int ft_putstr_justify(char *arg, int *flags)
{
    int len;

    if (flags[1])
    {
        len = write(1, arg, ft_strlen(arg));
        if (len < 0)
        {
            free(arg);
            return (-1);
        }
        len = ft_putjustify(flags[3] - ft_strlen(arg), flags[1]);
    }
    else
    {
        len = ft_putjustify(flags[3] - ft_strlen(arg), flags[1]);
        if (len < 0)
        {
            free(arg);
            return (-1);
        }
        len = write(1, arg, ft_strlen(arg));
    }
    if (len < 0)
        return (-1);
    return (flags[3]);
}

int ft_putstr(char *arg, int *flags)
{
    char    *res;
    int     len;

    res = arg;
    if (flags[4])
    {
        res = ft_substr(res, 0, flags[4]);
        free(arg);
        if (!res)
        {
            free(flags);
            return (-1);
        }
    }
    if (flags[3])
    {
        len = ft_putstr_justify(res, flags);
        free(res);
        return (len);
    }
    else
    {
        len = write(1, res, ft_strlen(arg));
        free(res);
        return (len);
    }
}