NAME = test
CC = cc
FLAGS = -Wall -Wextra -Werror -g
SRC = cdpwd.c \
	echo.c \
	utils.c
AR = ar rcs
OBJECTS = $(SRC:.c=.o)
%$.o: %$.c
	$(CC) $(FLAGS) -c $< -o $@ 
$(NAME): $(OBJECTS)
	$(CC) $(SRC) $(FLAGS) -o $(NAME) -lreadline
all: $(NAME)
clean: 
	$(RM) $(OBJECTS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
