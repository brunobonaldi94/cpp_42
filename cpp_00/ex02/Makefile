# ==============================================================================
# VARIABLES
# ==============================================================================
NAME			:=	Account
RESULT_LOG_FILE	:=	result.log
INPUT_LOG_FILE  :=	input.log
CPP				:=	c++
FLAGS			:=	-g3 -Wall -Werror -Wextra -std=c++98
MAKE			:=	make

SRCS			:=	Account.cpp tests.cpp
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
					@echo "$(WHT)Compiling Account...$(EOC)"
					@$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
					@echo "$(GREEN)Account build completed.$(EOC)"
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

test:	all run
	LOG=$$(cat $(RESULT_LOG_FILE) | awk 'NR=1{print $1}' | sed -n 's/.*\[\([^]]*\)\].*/\1/p' | head -n 1 ); \
	cat 19920104_091532.log | sed "s/19920104_091532/$${LOG}/g" > $(INPUT_LOG_FILE) 
	diff $(INPUT_LOG_FILE) $(RESULT_LOG_FILE)

run:	
	./$(NAME) > $(RESULT_LOG_FILE)

valgrind:
			@valgrind -s --leak-check=full --show-leak-kinds=all \
			--track-origins=yes --log-fd=9 ./$(NAME) 9>memcheck.log

.PHONY:		all clean fclean re run test
