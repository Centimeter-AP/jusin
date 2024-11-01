NAME		=	textRPG

SRCS		=	./MainGame/MainGame.cpp\
				./Character/Character.cpp\
				./Monster/Monster.cpp\
				./Player/Player.cpp\
				./System/System.cpp\
				./Field/Field.cpp\
				./main.cpp

OBJS		=	$(SRCS:%.cpp=%.o)

CC			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++11

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				@$(CC) -o $(NAME) $(OBJS)
				@echo "\n  😃\033[42;37;1m make complete \033[0m😃\n"
				@echo "\033[1mfile name: \033[30;47m ./"$(NAME)" \033[0m"

%.o			:	%.cpp
				@$(CC) $(FLAGS) -c $^ -o $@


clean		:
				@rm -f $(OBJS)
				@echo "\n❗️\033[41;36;1m object file deleted \033[0m❗️\n"

fclean		:	clean
				@rm -f $(NAME)
				@echo " ❗️\033[41;36;1m all file deleted \033[0m❗️\n"

re			:	
				@echo "\n     ⭐️\033[42;37;1m MAKE RE \033[0m⭐️\n"
				@make fclean
				@make all

.PHONY		:	all clean fclean re bonus