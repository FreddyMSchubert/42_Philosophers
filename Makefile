NAME = philo

SRC = $(shell find ./src -name "*.c")
OBJ = $(patsubst %.c,obj/%.o,$(SRC))

CFLAGS = -Wall -Werror -Wextra
DEBUG = -g -fsanitize=address

obj/%.o: %.c
	@mkdir -p $(@D)
	cc $(CFLAGS) -c $< -o $@ $(DEBUG)

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME) $(DEBUG)

all: $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

fcomp:
	@echo "Checking code style..."
	cd src && norminette
	@echo "Building everything from scratch..."
	make fclean
	make all
	@echo "Cleaning up..."
	make clean
	@echo "All clean and shiny!"
	clear
comp:
	make all
	make clean
	@echo "Ready to roll! 🚀"
	clear

.PHONY: all clean fclean re comp
