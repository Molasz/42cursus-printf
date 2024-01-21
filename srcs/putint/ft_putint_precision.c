#include "../../ft_printf.h"

int	ft_putint_precision(char *num, t_flags *flags, int n, size_t len)
{
	int	sign_len;

	sign_len = 0;
	if (flags->justify == '0')
	{
		if (flags->sign || n < 0)
		{
			if (ft_putint_pre(n, flags->sign) < 0)
				return (-1);
		}
		if (ft_putjustify('0', flags->precision - len) < 0)
			return (-1);
		if (flags->len > flags->precision)
		{
			if (ft_putjustify('0', flags->len - flags->precision) < 0)
				return (-1);
		}
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
		if (ft_putjustify('0', flags->precision - len) < 0)
			return (-1);
		if (write(1, num, len) < 0)
			return (-1);;
		if (flags->len > flags->precision)
		{
			if (ft_putjustify(' ', flags->len - flags->precision) < 0)
				return (-1);
		}
	}
	else
	{
		if (flags->len > flags->precision)
		{
			if (ft_putjustify(' ', flags->len - flags->precision) < 0)
				return (-1);
		}
		if (flags->sign || n < 0)
		{
			if (ft_putint_pre(n, flags->sign) < 0)
				return (-1);
		}
		if (ft_putjustify('0', flags->precision - len) < 0)
			return (-1);
		if (write(1, num, len) < 0)
			return (-1);
	}
	if (n < 0 || flags->sign)
		sign_len = 1;
	if (flags->len + sign_len > flags->precision)
		return (flags->len + sign_len);
	return (flags->precision + sign_len);
}