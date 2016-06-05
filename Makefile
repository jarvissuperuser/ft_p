C = gcc

F = -c

SR =	ft_printf.c \
	print.c \
	len2.c
H = ft_printf.h

O =		ft_printf.o \
		print.o \
		len2.o
LI = 	libfp.a
all : lib

lib : pack
	ar rc $(LI) $(O)

pack:
	$(C) $(F) $(SR)
	
clean : 
	/bin/rm $(O) 

