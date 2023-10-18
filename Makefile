NAME	= get_next_line.a

CC		= cc
CFALGS	= -Wall -Werror -Wextra
ARFLAGS	= rcs
RM		= rm -rf

SRC		= 	get_next_line\
			get_next_line_utils\

BONUS_SRC	=	get_next_line_bonus\
			get_next_line_utils_bonus\

SRCS	= 	$(addsuffix .c, $(SRC))

BONUS_SRCS =	$(addsuffix .c, $(BONUS_SRC))

OBJS	=	$(SRCS:.c=.o)

BONUS_OBJS =	$(BONUS_SRCS:.c=.o)

all:		$(NAME)

bonus:		$(NAME)

$(NAME):	$(OBJS)
		ar $(ARFLAGS) $(NAME) $(OBJS)

$(NAME): 	$(BONUS_OBJS)
		ar $(ARFLAGS) $(NAME) $(BONUS_OBJS)

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: fclean all