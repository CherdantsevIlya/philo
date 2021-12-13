NAME	=	philo

SRCS 	= 	main.c \
			parsing.c \
			philo.c \
			utils.c

OBJS	=	$(SRCS:.c=.o)

HEADER	=	philo.h

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g
RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
			@$(CC) $(OBJS) -o $(NAME) -pthread
			@printf "\x1b[1m\x1b[35m 🍝 philo is ready 🍜 \x1b[22m\n"

%.o		:	%.c $(HEADER)
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean	:
			@$(RM) $(OBJS)
			@printf "\x1b[1m\x1b[31mclean philo 🧹 \x1b[0m\n"

fclean	:	clean
			@$(RM) $(NAME)
			@printf "\x1b[1m\x1b[31mfclean philo 🗑 \x1b[0m\n"

re		:	fclean all

.PHONY	: 	all clean fclean re



