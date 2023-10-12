NAME = PhoneBook

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)

O_SRCS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(O_SRCS)
	$(CC) $(CFLAGS) $(O_SRCS) -o $(NAME)

clean:
	rm -f $(O_SRCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
