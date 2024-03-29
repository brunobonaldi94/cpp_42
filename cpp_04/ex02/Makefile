# ==============================================================================
# VARIABLES
# ==============================================================================
NAME			:=	main
RESULT_LOG_FILE	:=	result.log
INPUT_LOG_FILE  :=	input.log
CPP				:=	c++
FLAGS			:=	-g3 -Wall -Werror -Wextra -std=c++98 -fsanitize=address
MAKE			:=	make

SRCS			:=	AAnimal.cpp Dog.cpp Cat.cpp Brain.cpp main.cpp
OBJS			:=	$(SRCS:.cpp=.o)

# ==============================================================================
# COLORS
# ==============================================================================

GREEN			:=	\033[1;32m
RED				:=	\033[1;31m
WHT				:=	\033[1;37m
EOC				:=	\033[1;0m

# ==============================================================================
# RECIPES
# ==============================================================================

all:		$(NAME)

%.o:		%.cpp
	@$(CPP) $(FLAGS) -c $< -o $@

$(NAME):			$(OBJS)
					@echo "$(WHT)Compiling $(NAME)...$(EOC)"
					@$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
					@echo "$(GREEN)$(NAME) build completed.$(EOC)"
					@tput setaf 5

clean:
					@echo "$(WHT)Removing .o files...$(EOC)"
					@rm -f $(OBJS) $(RESULT_LOG_FILE) $(INPUT_LOG_FILE)
					@echo "$(GREEN)Clean done.$(EOC)"

fclean:		clean
					@echo "$(WHT)Removing object- and binary -files...$(EOC)"
					@rm -f $(NAME)
					@echo "$(GREEN)Fclean done.$(EOC)"

re:			fclean all

run:	all
	@./$(NAME)

valgrind:
			@valgrind -s --leak-check=full --show-leak-kinds=all \
			--track-origins=yes --log-fd=9 ./$(NAME) 9>memcheck.log

.PHONY:		all clean fclean re run
