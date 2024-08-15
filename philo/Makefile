NAME = philo
CFLAGS = -Wextra -Wall -Werror -pthread -Iinclude

SRCS =	src/main.c \
		src/tools.c \
		src/atoi.c \
		src/init.c \
		src/delete.c \
		src/thread.c \
		src/info.c \
		src/action_fork.c \
		src/action_philo.c \
		src/set_philo.c \
		src/listener.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@cc $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@cc $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
