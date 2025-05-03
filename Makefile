NAME_1 = server
NAME_2 = client

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = src

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)

RM = rm -f

SER_SRC =	src/server.c \
			src/utils.c 
SER_OBJ = $(SER_SRC:.c=.o)

CLI_SRC =	src/client.c \
			src/utils.c 
CLI_OBJ = $(CLI_SRC:.c=.o)

all: libft $(NAME_1) $(NAME_2)

$(NAME_1): $(SER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_1) $(SER_OBJ) $(LIBFT)

$(NAME_2): $(CLI_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_2) $(CLI_OBJ) $(LIBFT)

libft:
	$(MAKE) -C $(LIBFT_DIR) -s

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(CLI_OBJ) $(SER_OBJ)

fclean: clean
	$(RM) $(NAME_1) $(NAME_2)
	$(MAKE) -C $(LIBFT_DIR) fclean -s

re: fclean all

.PHONY: all clean fclean re libft

