NAME = libft.a
SOURCE_FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJECT_FILES = $(SOURCE_FILES:.c=.o)
SRC_DIR = ./srcs/
SRCS = $(addprefix $(SRC_DIR),$(SOURCE_FILES))
OBJS = $(addprefix $(SRC_DIR),$(OBJECT_FILES))
HEADER = includes/ft.h

all: $(NAME)

$(SRC_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	gcc -Wall -Wextra -Werror -c $< -o $@ 

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
