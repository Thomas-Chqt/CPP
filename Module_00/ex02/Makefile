# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 12:15:17 by tchoquet          #+#    #+#              #
#    Updated: 2023/09/02 18:31:00 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT 			= .
SRCS_DIR		= ${ROOT}
INCLUDES_DIR 	= ${ROOT}
BUILD_DIR		= ${ROOT}/.build

SRC			= ${SRCS_DIR}/tests.cpp ${SRCS_DIR}/Account.cpp
OBJ			= ${patsubst ${SRCS_DIR}%, ${BUILD_DIR}%, ${SRC:.cpp=.o}}
OBJ_DEBUG	= ${OBJ:.o=_debug.o}

CXX 			= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98
debug: CXXFLAGS	= -g -D MEMCHECK -std=c++98

NAME		= ${ROOT}/account
NAME_DEBUG	= ${NAME}_debug


.PHONY: all clean fclean re debug cleandebug fcleandebug redebug cleanbuild


all: ${NAME}

${NAME}: ${OBJ}
	@${CXX} -o $@ $^
	@echo "Executable created at $@."

clean:
	@rm -rf ${OBJ}
	@echo "Release object files in ${BUILD_DIR} deleted."

fclean: clean
	@rm -rf ${NAME}
	@echo "${NAME} deleted."

re: fclean all




debug: ${NAME_DEBUG}

${NAME_DEBUG}: ${OBJ_DEBUG}
	@${CXX} -o $@ $^
	@echo "Executable created at $@."

cleandebug:
	@rm -rf ${OBJ_DEBUG}
	@echo "Debug object files in ${BUILD_DIR} deleted."

fcleandebug: cleandebug
	@rm -rf ${NAME_DEBUG}
	@echo "${NAME_DEBUG} deleted."

redebug: fcleandebug debug




cleanbuild:
	@rm -rf ${BUILD_DIR}
	@echo "Build folder deleted."



${BUILD_DIR}/%_debug.o ${BUILD_DIR}/%.o: ${SRCS_DIR}/%.cpp | ${BUILD_DIR}
	${CXX} ${CXXFLAGS} -o $@ -c $< -I${INCLUDES_DIR}


#folders
${BUILD_DIR}:
	mkdir -p $@