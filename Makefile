SOURCES	= ft_printf.c itoa.c string.c
OBJECTS	= ${SOURCES:.c=.o}
LIBFT_OBJECTS = libft/*.o
NAME = libftprintf.a

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

libftprintf.a: ${OBJECTS} libft/libft.a
	ar -rc libftprintf.a ${OBJECTS} ${LIBFT_OBJECTS}

all: libftprintf.a

libft/libft.a:
	make -C libft

clean:
	rm -f ${OBJECTS}
	rm -f *.h.gch *.out
	make -C libft clean

fclean: clean
	rm -f libftprintf.a libft/libft.a

re: fclean all