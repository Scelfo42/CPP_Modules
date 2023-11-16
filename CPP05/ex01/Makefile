NAME    :=  Maggots

CC      :=	c++

FLAGS   :=	-g -Wall -Wextra -Werror -std=c++98

SRCS	:=	main.cpp			\
			Bureaucrat.cpp		\
			Form.cpp

OBJS     := $(SRCS:.cpp=.o)

# COLORS ================================================================= #

RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
WHITE = \033[0;97m

# ======================================================================== #

%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling:$(WHITE) $<"

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(YELLOW)- Program Name: $(WHITE)${NAME}"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}"
	@echo "$(YELLOW)- Flags: $(WHITE)${FLAGS}"

clean:
	@rm -f $(OBJS)
	@rm -f $(OUTFILE)
	@echo "$(RED)All $(CYAN)$(NAME)$(RED)'s objects removed with $(WHITE)${RM} $(YELLOW)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(INFILE)
	@echo "$(RED)...and $(CYAN)${NAME} $(RED)has been removed"

re: fclean all

.PHONY: all clean fclean re
.SILENT:
