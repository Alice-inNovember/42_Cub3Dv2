NAME	=	LIBGNL.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIBC	=	ar rcs
RM		=	rm -rf
SRCS	=	gnl.c
OBJS	=	${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re :
	fclean
	all

.PHONY : all clean fclean re