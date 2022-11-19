SRCS	=	ft_printf.c utils.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
AR		=	ar rcs

NAME	=	libftprintf.a

all	:	$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)
clean	:	$(OBJS)
	rm $(OBJS)
fclean	:	clean
	rm *.a
