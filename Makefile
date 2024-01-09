NAME = philo

SRC = $(shell find ./src -name "*.c")
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra
DEBUG = -g -fsanitize=address

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME) $(DEBUG)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $< $(DEBUG)

all: $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

fcomp:
	cd src && norminette
	make fclean
	make all
	make clean
	clear
comp:
	make all
	make clean
	clear

.PHONY: all clean fclean re comp