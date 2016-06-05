/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ft_printf.h
 * Author: timothy
 *
 * Created on 31 May 2016, 7:14 PM
 */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#define bfr = 4096;

typedef struct p_str {
	int para;
	int il;
	int fl;
	char * str_or;
	char * final;
	char c;
	int cnt;
} p_str;

typedef struct flr {
	char * flag;
	char selector;
} flr;

void init(p_str *, char *);

int stc(char c);

int setflr(flr * f, char * str);

void ft_printf(const char * str, ...);

void ft_free(p_str * p, flr * f, char *s);

void ft_putstrs(char *str);

int ft_strlens(const char *str);

#endif /* FT_PRINTF_H */

