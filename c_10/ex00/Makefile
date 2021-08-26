NAME = ft_display_file
SOURCE = main.c
OBJECT = main.o
HEADER = ft.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(OBJECT): $(SOURCE) $(HEADER)
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	gcc $(OBJECT) -o $(NAME) 

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
