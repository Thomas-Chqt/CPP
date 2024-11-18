# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 12:15:17 by tchoquet          #+#    #+#              #
#    Updated: 2024/02/07 19:08:38 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET_TYPE	= release

BUILD_DIR = .build

    SRC = main.cpp RPN.cpp
    OBJ = ${foreach file, ${SRC:.cpp=.o}, ${BUILD_DIR}/${notdir ${file}}}
ifeq (${TARGET_TYPE}, debug)
    OBJ := ${OBJ:.o=_debug.o}
else ifneq (${TARGET_TYPE}, release)
    $(error Bad TARGET_TYPE)
endif

    CXX 		= c++
    CXXFLAGS	= -std=c++98

ifeq (${TARGET_TYPE}, release)
    CXXFLAGS	+= -Wall -Wextra -Werror
else ifeq (${TARGET_TYPE}, debug)
    CXXFLAGS	+= -g -D DEBUG
else
    $(error Bad TARGET_TYPE)
endif

    NAME = RPN
ifeq (${TARGET_TYPE}, debug)
    NAME := ${NAME}_debug
else ifneq (${TARGET_TYPE}, release)
    $(error Bad TARGET_TYPE)
endif


.PHONY: all clean fclean re debug redebug


all: ${NAME}

${NAME}: ${OBJ}
	@${CXX} ${LDFLAGS} ${LDLIBS} -o $@ $^
	@echo "Executable created at $@."

${BUILD_DIR}/%_debug.o ${BUILD_DIR}/%.o: %.cpp | ${BUILD_DIR}
	${CXX} ${CXXFLAGS} ${CPPFLAGS} -o $@ -c $< 

clean:
	@rm -rf ${BUILD_DIR}
	@echo "Build folder deleted"

fclean: clean
	@rm -rf ${NAME}
	@echo "${NAME} deleted"
	@rm -rf ${NAME}_debug
	@echo "${NAME}_debug deleted"


re: fclean all

debug:
	@make TARGET_TYPE=debug all

redebug: fclean debug


#folders
${BUILD_DIR}:
	mkdir -p $@
