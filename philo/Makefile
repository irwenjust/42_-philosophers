NAME = philo
CFLAGS = -Wextra -Wall -Werror -pthread -Iinclude

SRCS =	src/main.c \
		src/tools.c \
		src/atoi.c \
		src/init.c

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

re: clean all

.PHONY: all clean fclean re
