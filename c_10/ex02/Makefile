NAME = ft_tail
SOURCE = main.c ft_atoi.c error_print.c tail.c
OBJECT = ${SOURCE:.c=.o}
HEADER = ft.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	gcc $(OBJECT) -o $(NAME) 

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
