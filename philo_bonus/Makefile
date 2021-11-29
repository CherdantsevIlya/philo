NAME	=	philo_bonus

SRCS 	= 	main_bonus.c \
			parsing_bonus.c \
			philo_bonus.c \
			routine_bonus.c \
			utils_bonus.c \
			utils2_bonus.c \

OBJS	=	$(SRCS:.c=.o)

HEADER	=	philo_bonus.h

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
			@$(CC) $(OBJS) -I. -o $(NAME) -pthread
			@printf "\x1b[1m\x1b[35m 🍝 philo_bonus is ready 🍜 \x1b[22m\n"

%.o		:	%.c $(HEADER)
			@$(CC) $(CFLAGS) -I. -c $< -o $(<:.c=.o)

clean	:
			@$(RM) $(OBJS)
			@printf "\x1b[1m\x1b[31mclean philo_bonus 🧹 \x1b[0m\n"

fclean	:	clean
			@$(RM) $(NAME)
			@printf "\x1b[1m\x1b[31mfclean philo_bonus 🗑 \x1b[0m\n"

re		:	fclean all

.PHONY	: 	all clean fclean re



