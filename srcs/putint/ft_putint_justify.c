#include "../../ft_printf.h"

int	ft_putint_justify(char *num, t_flags *flags, int n, size_t len)
{
	if (flags->justify == '0')
	{
		if (flags->sign || n < 0)
		{
			if (ft_putint_pre(n, flags->sign) < 0)
				return (-1);
		}
		if (ft_putjustify('0', flags->len - len) < 0)
			return (-1);
		if (write(1, num, len) < 0)
			return (-1);
	}
	else if (flags->justify == '-')
	{
		if (flags->sign || n < 0)
		{
			if (ft_putint_pre(n, flags->sign) < 0)
				return (-1);
		}
		if (write(1, num, len) < 0)
			return (-1);
		if (ft_putjustify(' ', flags->len - len) < 0)
			return (-1);
	}
	else
	{
		if (ft_putjustify(' ', flags->len - len) < 0)
			return (-1);
		if (flags->sign || n < 0)
		{
			if (ft_putint_pre(n, flags->sign) < 0)
				return (-1);
		}
		if (write(1, num, len) < 0)
			return (-1);
	}
	if (flags->sign || n < 0)
		flags->len++;
	return (flags->len);
}