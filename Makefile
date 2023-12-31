# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 14:26:53 by tchoquet          #+#    #+#              #
#    Updated: 2023/10/27 14:30:59 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR		= $(shell find sources -type d)
INCLUDES_DIR	= $(shell find includes -type d) Libft/includes Graphics/includes
BUILD_DIR		= .build

SRC = $(foreach dir, ${SRCS_DIR}, $(wildcard ${dir}/*.c))
OBJ = $(foreach file, ${SRC:.c=.o}, ${BUILD_DIR}/$(notdir ${file}))

CC			= cc
CPPFLAGS	= $(foreach dir, ${INCLUDES_DIR}, -I${dir})
CFLAGS		= -O3 -Wall -Wextra -Werror
LDFLAGS		= -L Libft -L MiniLibX -L Graphics 
LDLIBS		= -l ft -l Graphics -l mlx -lz -framework OpenGL -framework AppKit

NAME	= cub3D

vpath %.c ${SRCS_DIR}
vpath %.h ${INCLUDES_DIR}


.PHONY: all clean fclean re dep_all dep_clean dep_fclean


all: ${NAME}

${NAME}: dep_all ${OBJ} | ${EXPORT_LIB_DIR}
	@${CC} ${LDFLAGS} -o $@ ${OBJ} ${LDLIBS}
	@echo "Executable created at $@"

${BUILD_DIR}/%.o: %.c | ${BUILD_DIR}
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ -c $<

clean: dep_clean
	@rm -rf ${BUILD_DIR}
	@echo "Build folder deleted (cub3d)"

fclean: dep_fclean
	@rm -rf ${BUILD_DIR}
	@echo "Build folder deleted (cub3d)"
	@rm -rf ${NAME}
	@echo "${NAME} deleted."

re: fclean all

dep_all:
	@make -C Libft all
	@make -C MiniLibX all
	@make -C Graphics all

dep_clean:
	@make -C Libft clean	
	@make -C MiniLibX clean
	@make -C Graphics clean

dep_fclean:
	@make -C Libft fclean
	@make -C MiniLibX fclean
	@make -C Graphics fclean

#folders
${EXPORT_INCLUDE_DIR} ${EXPORT_LIB_DIR} ${BUILD_DIR}:
	@mkdir -p $@
	@echo "Folder $@ created"
