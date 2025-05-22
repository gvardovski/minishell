NAME = test
CC = cc
FLAGS = -Wall -Wextra -Werror -g
SRC = cdpwd.c \
	echo.c \
	env.c
AR = ar rcs
OBJECTS = $(SRC:.c=.o)
MINISHELL = ../objs/minishell.a
PRINTFLINFT = ../libft/ft_printf/libftprintf.a
%$.o: %$.c
	$(CC) $(FLAGS) -c $< -o $@ 
$(NAME): $(OBJECTS)
	make -C ../
	$(CC) $(SRC) $(MINISHELL) $(PRINTFLINFT) $(FLAGS) -o $(NAME)  -lreadline 
all: $(NAME)	
clean: 
	$(RM) $(OBJECTS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
