NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
INCLUDE = push_swap.h

SRCS = algorithm_utils.c \
		algorithm.c \
		error.c \
		init_a.c \
		main.c \
		move_push.c \
		move_rotate.c \
		move_rrotate.c \
		move_swap.c \
		set_nodes.c \
		sort_small.c \
		split.c
		
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