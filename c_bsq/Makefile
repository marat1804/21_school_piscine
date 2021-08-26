NAME = bsq
SOURCE = ft_split.c funcs.c main.c map_processing.c map_utils.c utils.c memory_control.c ft_strdup.c read_from_stdin.c
OBJECT = ${SOURCE:.c=.o}
OBJDIR = ./obj/
OBJ = ${addprefix ${OBJDIR}, ${OBJECT}}
HEADER = map.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

${OBJDIR}%.o: %.c $(HEADER)
	mkdir -p ${OBJDIR}
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
