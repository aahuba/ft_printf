NAME	=	libft.a

CFLAGS	=	-Wall -Werror -Wextra -c

LIB_SRC	=	../../sources/s_libft
LIB_BASE = 	ft_atoi.c \
			ft_bzero.c \
			ft_countwords.c \
			ft_memalloc.c \
			ft_strjoin.c \
			ft_strsplit.c \
			ft_putstr.c	\
			ft_strstr.c \
			ft_strlen.c	\
			ft_strsub.c \
			ft_strcat.c	\
			ft_memcpy.c	\
			ft_strchr.c	\
			ft_memdel.c \
			ft_strcpy.c	\
			ft_strncpy.c \
			ft_putchar.c \
			ft_strdel.c	\
			ft_strndup.c \
			ft_strdup.c	\
			ft_putendl.c \
			ft_strnew.c \
			ft_lstnew.c \
			ft_lstadd.c \
			ft_get_next_line.c \
			ft_free.c \

INCLUDES	=	../../includes

OBJS = $(addprefix $(LIB_SRC)/, $(LIB_BASE:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
		@ar rcs $@ $^
		@ranlib $@

$(LIB_SRC)/%.o: $(LIB_SRC)/%.c
	@gcc $(CFLAGS) -o $@ $< -I $(INCLUDES)

clean:
	@rm -f $(OBJS)

fclean:	clean
		@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re