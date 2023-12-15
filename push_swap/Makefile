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

test3:            $(NAME)
				$(eval ARG = $(shell shuf -i 0-100 -n 3))
				./push_swap $(ARG) | ./checker_linux $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

test5:            $(NAME)
				$(eval ARG = $(shell shuf -i 0-5000 -n 5))
				./push_swap $(ARG) | ./checker_linux $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

test100:        $(NAME)
				$(eval ARG = $(shell shuf -i 0-5000 -n 100))
				./push_swap $(ARG) | ./checker_linux $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

test500:        $(NAME)
				$(eval ARG = $(shell shuf -i 0-5000 -n 500))
				./push_swap $(ARG) | ./checker_linux $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l