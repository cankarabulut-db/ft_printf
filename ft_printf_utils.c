#include "ft_printf.h"
int ft_putchar(char a)
{
	write(1,&a,1);
	return (1);
}
int ft_putstr(char *str)
{
	int i;

	i = 0;
	if(!str)
		return (write(1,"(null)",6));
	while(str[i])
		ft_putchar(str[i++]);
	return (i);
}

int ft_putnbr(int a,int inx)
{
	if(a == -2147483648)
		ft_putstr("-2147483648");
	else if(a < 0)
	{
		a = -a;
		ft_putchar('-');
		ft_putnbr(a);
	}
	else if(a >= 10)
	{
		
	}
}

