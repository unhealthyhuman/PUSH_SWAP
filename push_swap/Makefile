.SILENT:

NAME = push_swap

CC = cc

FLAGS = -Wall -Werror -Wextra -g

SRCS = main.c\
node_utils.c\
movement.c\
movement2.c\
sorter.c\
sort_utils.c\
parsing_utils.c

OBJS := $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I./

all: $(NAME)

$(NAME): $(OBJS)
	cd libft && $(MAKE) && $(MAKE) bonus
	cc $(FLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

clean:
	cd libft && $(MAKE) fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re