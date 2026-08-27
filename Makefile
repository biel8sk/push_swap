NAME        = push_swap
CC          = cc
C_FLAGS     = -Wall -Werror -Wextra -I includes -g
SRCS_FILES  = main.c stack_utils.c operations_base.c mult_operations_ps.c push_operations.c rotate_operations.c\
			  sort_simple.c swap_operations.c compute_disorder.c sort_medium.c stack_build.c
SRC_DIR     = src/
SRCS        = $(addprefix $(SRC_DIR), $(SRCS_FILES))

OBJ_DIR     = obj
OBJ_FILES   = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

LIBS        = libs
LIBFT       = $(LIBS)/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBS)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(C_FLAGS) $(OBJ_FILES) -L$(LIBS) -lft -o $(NAME) -g

$(OBJ_DIR)/%.o: src/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBS) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBS) fclean

re: fclean all

.PHONY: all clean fclean re
