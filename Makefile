NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
INCLUDES = -I./inc -I./libft/
SRC_PATH = src/
OBJ_PATH = obj/

SRCS = $(SRC_PATH)/main.c \
		$(SRC_PATH)/cost_calculation.c \
		$(SRC_PATH)/create_list.c \
		$(SRC_PATH)/error_handling.c \
		$(SRC_PATH)/input_check.c \
		$(SRC_PATH)/instructions_push.c \
		$(SRC_PATH)/instructions_revrotate.c \
		$(SRC_PATH)/instructions_rotate.c \
		$(SRC_PATH)/instructions_swap.c \
		$(SRC_PATH)/list_manipulations.c \
		$(SRC_PATH)/pushing_back.c \
		$(SRC_PATH)/sort_three_elements.c \
		$(SRC_PATH)/sorting.c \
		$(SRC_PATH)/split_parser.c \

SRC	= $(addprefix $(SRC_PATH), $(SRCS))
OBJ = $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))

all:	$(NAME) 

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C ./libft


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^

clean: 
	@$(MAKE) -C ./libft clean 
	@rm -rf $(OBJ_PATH)

fclean: clean
	@$(MAKE) -C ./libft fclean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
