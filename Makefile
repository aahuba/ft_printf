NAME = ft_printf

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra

ch:
	@make fclean
	@make all
	@./ft_printf

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	@gcc -g $(OBJ) libft/libft.a -I libft -o $(NAME)

%.o: %.c ft_printf.h
	@gcc -g $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@rm -f libft/libft.a
	@make fclean -C libft

re: fclean all

libft/libft.a:
	@make -C libft

git:
	git add *
	git commit -m "auto comment"
	git push
