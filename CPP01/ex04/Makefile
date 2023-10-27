NAME = Replacer

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS =	main.cpp \

O_SRCS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(O_SRCS)
	$(CC) $(CFLAGS) $(O_SRCS) -o $(NAME)

clean:
	$(RM) $(O_SRCS)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
