NAME		= push_swap
CC			= cc
C_FLAGS		= -Wall -Werror -Wextra -I includes
SRCS	= 	main.c 

OBJ_FILES	= $(SRCS:.c=.o)

LIBS	= libs

LIBFT	= $(LIBS)/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBS)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(C_FLAGS) $(OBJ_FILES) -L./libs -lft -o $(NAME)

%.o : %.c $(LIBFT)
	$(CC) $(C_FLAGS) -c $< -o $@

clean: 	
	rm -f $(OBJ_FILES)
	$(MAKE) -C $(LIBS) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBS) fclean

re: fclean all

.PHONY: all clean fclean re