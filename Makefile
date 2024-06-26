NAME			= ft_irc

SRC				= main.cpp						\
					utils/helpers.cpp			\
					utils/errors.cpp			\
					classes/Server.cpp

DIR_SRC		= src/

DIR_OBJ		= obj/

DIR_INC		= inc/

OBJ			= ${SRC:%.cpp=${DIR_OBJ}%.o}

CXX			= c++

DEP			= ${OBJ:%.o=%.d}

CPPFLAGS	= -Wall -Wextra -Werror -MMD -g3 -D_GLIBCXX_DEBUG -std=c++98 -c -I ${DIR_INC} 

RM 			= rm -f

RMDIR		= rm -rf

all: ${NAME}

${NAME} : ${OBJ}
	${CXX} $^ -o $@

${OBJ} : ${DIR_OBJ}%.o: ${DIR_SRC}%.cpp
	mkdir -p ${@D}
	${CXX} ${CPPFLAGS} $< -o $@
-include ${DEP}

clean:
	${RMDIR} ${DIR_OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re