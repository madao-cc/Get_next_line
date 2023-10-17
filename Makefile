NAME	= get_next_line.a

CC		= cc
CFALGS	= -Wall -Werror -Wextra
ARFLAGS	= rcs
RM		= rm -rf

SRC		= 	get_next_line\
			get_next_line_utils\

SRCS	= 	$(addsuffix .c, $(SRC))

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		ar $(ARFLAGS) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: fclean all