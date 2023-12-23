#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


int ft_putchar(char c)
{
	return (write(1,&c,1));
}
int ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1,&str[i++],1);
	return (i);
}
int ft_putnbr(long numan)
{

	if (numan >= 10)
		ft_putnbr(numan / 10);
	ft_putchar("0123456789"[numan % 10]);
}

int ft_check(va_list arg, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return(ft_putstr(va_arg(arg, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	
	return (0);

}

int test(char *str, ...)
{
	va_list arg;
	int i = 0;
	int size = 0;
	va_start(arg,str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_check(arg,str[++i]);
		}
		else
			size += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (size);
}
#include <stdlib.h>
int main()
{

	abort();
	printf("%i\n",test("deneme %c %s",'1',"yazi"));
}