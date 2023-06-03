# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 01:34:31 by thugueno          #+#    #+#              #
#    Updated: 2023/06/03 03:04:19 by thugueno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########################################
####	MAKE CONF						##

.DEFAULT_GOAL	:=	ft_lst

##########################################
####	FILES							##

#GOALS

LIBFT		:=	../../libft.a

NAME		:=	libft_ft_lst.a

#DIRECTORIES

INCLUDE		:=	../../include/

BUILD		:=	../../.build/

SRC			:=	src/

MODULE		:=	ft_lst/

#PREREQUISITES

SRCS		:=	ft_lstadd_back.c	\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_lstsize.c		\
				ft_lstadd_front.c	\
				ft_lstdelone.c		\
				ft_lstlast.c		\
				ft_lstnew.c			\

#TARGETS

OBJS		:=	${SRCS:%.c=${BUILD}${SRC}${MODULE}%.o}

DEPS		:=	${SRCS:%.c=${BUILD}${SRC}${MODULE}%.d}

##########################################
####	FLAGS							##

CC			:= 	clang

CFLAGS		:= 	-Werror -Wextra -Wall

ifdef DEBUG
	CFLAGS +=  -O0 -gdwarf-4
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
			@echo "${CCLEAN}${INDENT} Removing src/ft_lst objects${NOCOLOR}"

fclean:		clean
			@ar d ${LIBFT} ${OBJS}
			@${RM} ${NAME}
			@echo "${CFCLEAN}${INDENT} Removing ${NAME} module from ${LIBFT}${NOCOLOR}"

re:			fclean all

.PHONY:	all clean fclean re

##########################################
####	CUSTOM TARGETS					##

ft_lst:		all

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

.PHONY: ft_lst
