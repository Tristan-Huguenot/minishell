# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 21:01:03 by thugueno          #+#    #+#              #
#    Updated: 2023/05/24 14:46:54 by thugueno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########################################
####	MAKE CONF						##

.DEFAULT_GOAL	:=	all

##########################################
####	FILES							##

#GOALS

NAME	:=	minishell

LIBFT	:=	libft/libft.a

#DIRECTORY

INCLUDE	:=	include/

BUILD	:=	.build/

SRC		:=	src/

SRC0	:=	parsing/	\
			builtin/	\
			prompt/		\
			pipe/		\

#PREREQUISITES

SRCS	:=	src/main.c	\
			src/parsing/parsing_prompt.c	\
			src/prompt/prompt.c				\

#TARGETS

OBJS	:=	${SRCS:%.c=${BUILD}%.o}

DEPS	:=	${SRCS:%.c=${BUILD}%.d}

##########################################
####	FLAGS							##

CC			:=	clang

CFLAGS		:=	-Werror -Wextra -Wall

ifdef DEBUG
	CFLAGS +=  -g
else
	CFLAGS +=  -O3
endif

CPPFLAGS	:= -MP -MMD -I${INCLUDE} -I${dir ${LIBFT}}include/

LDFLAGS		:=	-L${dir ${LIBFT}} -l:${notdir ${LIBFT}} -lreadline

##########################################
####	DECORATION						##

#TEXT

INDENT		=	[${NAME}]:

#COLORS

CCOMPILE	:=	\033[36m

CCREATE		:=	\033[95m

CDONE		:=	\033[5;32m

CFCLEAN		:=	\033[31m

CCLEAN		:=	\033[33m

CCTAGS		:=	\033[38;5;200m

NOCOLOR		:=	\033[0m

##########################################
####	CUSTOM COMMANDS					##

RM			:=	rm -f

MAKE		:=	@make --no-print-directory TAB="${INDENT}"

ifdef DEBUG
	MAKE := ${MAKE} DEBUG=1 -C
else
	MAKE := ${MAKE} -C
endif

##########################################
####	MANDATORY TARGET				##

all:		libraries ${NAME}

${NAME}:	${OBJS}
			@echo "${CCREATE}${INDENT} Creating ${NAME}${NOCOLOR}"
			@${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}
			@echo "${CDONE}${INDENT} ${NAME} done.${NOCOLOR}"

clean:		ctags
			${MAKE} ${dir ${LIBFT}} clean
			@${RM} -r ${BUILD}
			@echo "${CCLEAN}${INDENT} Removing objects${NOCOLOR}"

fclean:		clean
			@${MAKE} ${dir ${LIBFT}} fclean
			@${RM} ${NAME}
			@echo "${CFCLEAN}${INDENT} Removing ${NAME}${NOCOLOR}"

re:			fclean all

-include ${DEPS}

.PHONY:		all clean fclean re

##########################################
####	CUSTOM TARGET					##

${OBJS}:			${BUILD}%.o:	%.c | ${BUILD}${SRC}${SRC0}
					@${CC} ${CFLAGS} -c ${CPPFLAGS} $< -o $@
					@echo "${CCOMPILE}${INDENT} Compiling $@${NOCOLOR}"

${BUILD}${SRC}:
					@mkdir -p ${BUILD}
					@mkdir -p ${addprefix ${BUILD}, ${SRC}}

${BUILD}${SRC}${SRC0}:	| ${BUILD}${SRC}
					@mkdir -p ${addprefix ${BUILD}${SRC}, ${SRC0}} 

##########################################
####	LIBRARIES TARGET				##

libraries:	${LIBFT}

${LIBFT}:
			${MAKE} ${dir ${LIBFT}}

.PHONY:	libraries ${LIBFT}

##########################################
####	CTAGS							##

CTAGS_FILE	:=	${SRC}										\
				${shell ls ${dir ${LIBFT}}src/*/*.c}		\
				${shell ls ${INCLUDE}*.h}					\
				${shell ls ${dir ${LIBFT_D}}${INCLUDE}*.h}	\

tags:		${CTAGS_FILE}
			@ctags -l c ${CTAGS_FILE}
			@echo "${CCTAGS}${INDENT} Making $@${NOCOLOR}"

ctags:
			@${RM} tags
			@echo "${CCLEAN}${INDENT} Deleting ctags${NOCOLOR}"

.PHONY:		ctags
