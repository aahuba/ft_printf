NAME = printf

LIB_SRC = ./sources/s_libft

INC_DIR = ./includes
INCS = -I $(INC_DIR)
SRC_DIR = ./sources/s_ftprintf
SRC_BASE = 	main.c \
			ft_printf.c

OBJ_DIR = ./objects

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_BASE:.c=.o))

CFLAGS = -Wall -Wextra

all: obj $(NAME)

$(NAME): libft/libft.a $(OBJS)
	gcc -g $(CFLAGS) $(OBJS) $(INCS) $(LIB_SRC)/libft.a -o $@
	
obj:
	mkdir -p objects

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h
	gcc $(CFLAGS) -c -o $@ $< $(INCS)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_SRC)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_SRC)

re: fclean all

libft/libft.a:
	make -C $(LIB_SRC)

.PHONY: clean all re fclean