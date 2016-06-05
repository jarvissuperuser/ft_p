#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

void	ft_do(int *i, char *s, int *index)
{
	if (*i < 0)
	{
		*(s)='-';
		*i *= -1;
		*index = 1;
	}
}

char nputc(int a)
{
	if (a < 10)
		return (char)a + '0';
	return (char)(a - 10) + 'A';
}
char *ft_o(int i,int d)
{
	p_str ps;

	ps.str_or = malloc(sizeof(char)*64);
	init(&ps,ps.str_or);
	ft_do(&i, ps.str_or, &ps.il);
	while (i >= 1)
	{
		*(ps.str_or+ps.il++) = nputc(i%d);
		i/=d;
	}
	i = --ps.il;
	if (*ps.str_or == '-')
		i += 1;
	while(ps.il>(i/2))
	{
		ps.c = *(ps.str_or+ps.il);
		*(ps.str_or+ps.il) = *(ps.str_or+(i-ps.il));
		*(ps.str_or+(i-ps.il--)) = ps.c;
	}
	return (ps.str_or);
}

void detYpe(char c,va_list v)
{
	if(c == 'i'|| c == 'd' || c == 'D')
		ft_putstrs(ft_o((int)va_arg(v,int), 10));
	if(c == 'x'|| c == 'X')
		ft_putstrs(ft_o((int)va_arg(v,int), 16));
	if(c == 'u')
		ft_putstrs(ft_o((int)(unsigned)va_arg(v,unsigned),10));
	if(c == 'p')
		ft_putstrs(ft_o((int)va_arg(v,int), 16));
	if(c == 'o'||c=='O')
		ft_putstrs(ft_o((int)va_arg(v,int), 8));
	if(c=='s'||c=='S')
		ft_putstrs((char*)va_arg(v,int));
	if(c=='c'){
		write(1,(char)va_arg(v,int),1);
	}
}

void ft_printf(const char * str,...)
{
	p_str p ;
	flr f;
	va_list vl;

	va_start(vl,str);
	init(&p,(char *)str);
	while(str[p.cnt])
	{
		if(str[p.cnt]!='%')
		{
			write(1,str[p.cnt++],1);
			continue;
		}
		else
		{
			++p.cnt;
			p.cnt = p.cnt + setflr(&f,(char*)(str + (p.cnt)));
			detYpe(f.selector,vl);
			++p.cnt;
			va_arg(vl,int);
			continue;
		}
	}
	//ft_free(&p,&f,(char *)str);
	va_end(vl);
}
