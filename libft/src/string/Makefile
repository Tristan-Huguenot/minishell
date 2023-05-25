# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 01:34:31 by thugueno          #+#    #+#              #
#    Updated: 2023/03/19 17:04:38 by thugueno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########################################
####	MAKE CONF						##

.DEFAULT_GOAL	:=	string

##########################################
####	FILES							##

#GOALS

LIBFT		:=	../../libft.a

NAME		:=	libft_string.a

#DIRECTORIES

INCLUDE		:=	../../include/

BUILD		:=	../../.build/

SRC			:=	src/

MODULE		:=	string/

#PREREQUISITES

SRCS		:=	ft_split.c	\
				ft_strchr.c	\
				ft_strchr_charset.c	\
				ft_strdup.c			\
				ft_striteri.c		\
				ft_strjoin.c		\
				ft_strjoin_free.c		\
				ft_strlcat.c		\
				ft_strlcpy.c		\
				ft_strlen.c			\
				ft_strmapi.c		\
				ft_strncmp.c		\
				ft_strnstr.c		\
				ft_strrchr.c		\
				ft_strtrim.c		\
				ft_substr.c			\
				ft_free_strs.c		\

#TARGETS

OBJS		:=	${SRCS:%.c=${BUILD}${SRC}${MODULE}%.o}

DEPS		:=	${SRCS:%.c=${BUILD}${SRC}${MODULE}%.d}

##########################################
####	FLAGS							##

CC			:= 	clang

CFLAGS		:= 	-Werror -Wextra -Wall

ifdef DEBUG
	CFLAGS +=  -g
else
	CFLAGS +=  -O3
endif

CPPFLAGS	:=	-MP -MMD -I${INCLUDE}

##########################################
####	CUSTOM COMMANDS					##

RM			:= 	rm -f

##########################################
####	DECORATION						##

#TEXTE

INDENT		:= [libft]:

ifdef TAB
	INDENT := ${TAB}${INDENT}
endif

#COLORS

CCOMPILE    :=  \033[36m

CCREATE     :=  \033[95m

CDONE       :=  \033[5;32m

CFCLEAN     :=  \033[31m

CCLEAN      :=  \033[33m

NOCOLOR     :=  \033[0m

##########################################
####	MANDATORY TARGETS				##

all:		${NAME}

clean:
			@${RM} -r ${BUILD}${SRC}${MODULE}
			@echo "${CCLEAN}${INDENT} Removing src/string objects${NOCOLOR}"

fclean:		clean
			@ar d ${LIBFT} ${OBJS}
			@${RM} ${NAME}
			@echo "${CFCLEAN}${INDENT} Removing ${NAME} module from ${LIBFT}${NOCOLOR}"

re:			fclean all

.PHONY:	all clean fclean re

##########################################
####	CUSTOM TARGETS					##

string:		all

${NAME}:	${OBJS}
			@echo "${CCREATE}${INDENT} Creating/updating ${NAME}${NOCOLOR}"
			@ar rcs ${NAME} ${OBJS}
			@ar rcs ${LIBFT} ${OBJS}
			@echo "${CDONE}${INDENT}${LIBFT} created/updated with ${NAME}${NOCOLOR}"

${OBJS}:	${BUILD}${SRC}${MODULE}%.o: %.c | ${BUILD}
			@${CC} ${CFLAGS} -c ${CPPFLAGS} $< -o $@
			@echo "${CCOMPILE}${INDENT}Compiling $@${NOCOLOR}"

${BUILD}:
			@mkdir -p ${BUILD}
			@mkdir -p ${addprefix ${BUILD}, ${SRC}}
			@mkdir -p ${addprefix ${BUILD}${SRC}, ${MODULE}}

-include ${DEPS}

.PHONY: string
