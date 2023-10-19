NAME = account

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	tests.cpp \
		Account.cpp

O_SRCS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(O_SRCS)
	$(CC) $(CFLAGS) $(O_SRCS) -o $(NAME)

clean:
	rm -rf $(O_SRCS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
