NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
INCLUDE = push_swap.h

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I $(INCLUDE)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re 