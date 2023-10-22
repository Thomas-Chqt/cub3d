# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 14:26:53 by tchoquet          #+#    #+#              #
#    Updated: 2023/10/22 14:22:12 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET_TYPE	= release# release | debug

ROOT			= .
SRCS_DIR		= $(shell find ${ROOT}/sources -type d)
INCLUDES_DIR	= $(shell find ${ROOT}/includes -type d)
BUILD_DIR		= ${ROOT}/.build

NAME_BASE		= ${ROOT}/cub3d


    SRC = $(foreach dir, ${SRCS_DIR}, $(wildcard ${dir}/*.c))
    OBJ = $(foreach file, ${SRC:.c=.o}, ${BUILD_DIR}/$(notdir ${file}))
ifeq (${TARGET_TYPE}, debug)
    OBJ := ${OBJ:.o=_debug.o}
else ifneq (${TARGET_TYPE}, release)
    $(error Bad TARGET_TYPE)
endif

    CC			= cc
    CPPFLAGS	= $(foreach dir, ${INCLUDES_DIR}, -I${dir})
    CFLAGS		=
    LDFLAGS		=
    LDLIBS		=
ifeq (${TARGET_TYPE}, release)
    CFLAGS		+= -O3 -Wall -Wextra -Werror
    LDLIBS		+= -l ft -l Graphics
else ifeq (${TARGET_TYPE}, debug)
    CFLAGS		+= -O0 -g -D DEBUG
    LDLIBS		+= -l memory_leak_detector -l ft_debug -l Graphics_debug
else
    $(error Bad TARGET_TYPE)
endif


ifeq (${TARGET_TYPE}, release)
    NAME = ${NAME_BASE}
else ifeq (${TARGET_TYPE}, debug)
    NAME = ${NAME_BASE}_debug
else
    $(error Bad TARGET_TYPE)
endif


vpath %.c ${SRCS_DIR}
vpath %.h ${INCLUDES_DIR}

.PHONY: all clean fclean re debug redebug


all: ${NAME}

${NAME}: ${OBJ} | ${EXPORT_LIB_DIR}
	@${CC} ${LDFLAGS} -o $@ $^ ${LDLIBS}
	@echo "Executable created at $@"

${BUILD_DIR}/%_debug.o ${BUILD_DIR}/%.o: %.c | ${BUILD_DIR}
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ -c $<

clean:
ifeq (${TARGET_TYPE}, release)
	@rm -rf ${BUILD_DIR}
	@echo "Build folder deleted"
endif

fclean: clean
ifeq (${TARGET_TYPE}, debug)
	@rm -rf ${NAME}
	@echo "${NAME} deleted."
else ifeq (${TARGET_TYPE}, release)
	@rm -rf ${NAME}
	@echo "${NAME} deleted"
	@make TARGET_TYPE=debug fclean
else
    $(error Bad TARGET_TYPE)
endif

re: fclean all

debug:
	@make TARGET_TYPE=debug all

redebug: fclean debug


#folders
${EXPORT_INCLUDE_DIR} ${EXPORT_LIB_DIR} ${BUILD_DIR}:
	@mkdir -p $@
	@echo "Folder $@ created"
