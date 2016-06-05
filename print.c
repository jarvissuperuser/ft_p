
#include <stdlib.h>

#include "ft_printf.h"

void init(p_str * p,char * c)
{
	p->cnt = 0;
	p->str_or = c;
	p->fl = 0;
	p->para = 0;
	p->il = ft_strlens(c);
}
int stc(char c)
{
	if (c == 'x'||c == 'X')
		return 4;
	if(c == 'u'||c == 'U'||c == 'd'||c == 'i')
		return 1;
	if (c == 's'||c == 'c'||c == 'S'||c == 'C')
		return 2;
	if(c == 'p')
		return 3;
	return 0;
}
int setflr(flr * f, char * str)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	f->flag = (char *) malloc(8*6);
	while(1)
	{
		if (!stc(str[i]))
		{
			f->flag[r++] = str[i];
		}
		else
		{
			f->selector = str[i];
			break;
		}
		i++;
	}
	return i;
}
void ft_free(p_str * p,flr * f,char *s)
{
	free(p->str_or);
	free(p->final);
	free(f->flag);
	free(s);
}
void	ft_putstrs(char *str)
{
	write(1, str, ft_strlens(str));
}