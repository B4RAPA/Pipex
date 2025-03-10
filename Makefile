GREEN = \033[0;32m
RESET = \033[0m

NAME = pipex

CC = cc

CFLAGS = -Werror -Wextra -Wall

INCLUDE = includes

PRINTF_LIB = includes/ft_printf/libftprintf.a
PRINTF_DIR = includes/ft_printf

LIBFT_DIR =	includes/libft/
LIBFT_NAME = libft.a
LIBFT_LIB = $(LIBFT_DIR)$(LIBFT_NAME)

SRCS = srcs/pipex.c\
		srcs/utils.c
		
OBJ = srcs/pipex.o\
		srcs/utils.o

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF_LIB) $(LIBFT_LIB)
		$(CC) $(CFLAGS) -I$(INCLUDE) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -o $(NAME) $(OBJ) \
		$(LIBFT_LIB) $(PRINTF_LIB)
		@echo "$(GREEN)pipex created$(RESET)"

$(PRINTF_LIB):
	@$(MAKE) -sC $(PRINTF_DIR)

$(LIBFT_LIB):
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "$(GREEN)LIBFT created$(RESET)"

clean:
		rm -rf $(OBJ)
		@$(MAKE) clean -sC $(PRINTF_DIR)
		@$(MAKE) clean -sC $(LIBFT_DIR)
fclean: clean
		rm -rf $(NAME)
		rm -rf $(LIBFT_LIB)
		rm -rf $(PRINTF_LIB)
re: fclean all

.PHONY: fclean clean all re