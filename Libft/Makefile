# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 16:24:59 by tchoquet          #+#    #+#              #
#    Updated: 2023/10/27 14:31:23 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR		= $(shell find sources -type d)
INCLUDES_DIR	= $(shell find includes -type d)
BUILD_DIR		= .build

SRC	= $(foreach dir, ${SRCS_DIR}, $(wildcard ${dir}/*.c))
OBJ	= $(foreach file, ${SRC:.c=.o}, ${BUILD_DIR}/$(notdir ${file}))

CC			= cc
CPPFLAGS	= $(foreach dir, ${INCLUDES_DIR}, -I${dir})
CFLAGS		= -O3 -Wall -Wextra -Werror

NAME	= libft.a

vpath %.c ${SRCS_DIR}
vpath %.h ${INCLUDES_DIR}


.PHONY: all clean fclean re


all: ${NAME}

${NAME}: ${OBJ} | ${EXPORT_LIB_DIR}
	@ar rc $@ $^
	@echo "Library created at $@"

${BUILD_DIR}/%.o: %.c | ${BUILD_DIR}
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ -c $<

clean:
	@rm -rf ${BUILD_DIR}
	@echo "Build folder deleted (Libft)"

fclean: clean
	@rm -rf ${NAME}
	@echo "${NAME} deleted"

re: fclean all


#folders
${EXPORT_INCLUDE_DIR} ${EXPORT_LIB_DIR} ${BUILD_DIR}:
	@mkdir -p $@
	@echo "Folder $@ created"
