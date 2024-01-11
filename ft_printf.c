#include "ft_printf.h"
int ochecker(char a)
{
	if (a == 'c' || a == 's' || a == 'd' || a == 'i' ||
		a == 'u' || a == 'x' || a == 'X' || a == 'p' || a == '%')
		return (1);
	return (0);
}
int checkprint(va_list list, char a)
{
	if (a == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (a == 's')
		return (ft_putstr(va_arg(list, char *)));
	else
		return (0);
}
int ft_printf(const char *str, ...)
{
	va_list list;
	int i;
	int len;

	i = 0;
	len = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ochecker(str[i + 1]))
			{
				len += checkprint(list, str[i + 1]);
				i += 2;
			}
		}
		else
		{
			len += ft_putchar(str[i++]);
		}
	}
	va_end(list);
	return (len);
}
