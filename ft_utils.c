#include "ft_printf.h"

char	*ft_chrstr(char c)
{
	char	*s;

	s = ft_calloc(sizeof (char), 2);
	if (!s)
		return (NULL);
	s[0] = c;
	return (s);
}

char	*ft_chrstrjoin(char c, char *s)
{
	char	*res;
	int		len;
	int		i;

	len = ft_strlen(s);
	res = ft_calloc(sizeof(char), len + 2);
	if (!res)
		return (NULL);
	res[0] = c;
	res[len - 1] = 0;
	i = 0;
	while (len > i)
	{
		i++;
		res[i] = s[i - 1];
	}
	free(s);
	return (res);
}