NAME = megaphone

CC = c++

STDFLAG = -std=c++98

CFLAGS = -Wall -Wextra -Werror $(STDFLAG)

SRCS = megaphone.cpp \

O_SRCS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRCS) $(O_SRCS)
	$(CC) $(CFLAGS) $(O_SRCS) -o $(NAME)

clean:
	rm -f $(O_SRCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
