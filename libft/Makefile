# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 01:34:31 by thugueno          #+#    #+#              #
#    Updated: 2023/07/13 22:39:15 by thugueno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########################################
####	MAKE CONF						##

.DEFAULT_GOAL	:=	all

##########################################
####	FILES							##

#GOALS

NAME		:=	libft.a

MEMORY_LIB	:=	src/memory/libft_memory.a

CHAR_LIB	:=	src/char/libft_char.a

WRITE_LIB	:=	src/write/libft_write.a

STRING_LIB	:=	src/string/libft_string.a

NUM_STR_LIB	:=	src/num_string/libft_num_string.a

MATH_LIB	:=	src/math/libft_math.a

FILE_LIB	:=	src/file/libft_file.a

FT_LST_LIB	:=	src/ft_lst/libft_ft_lst.a

FT_PF_LIB	:=	src/ft_printf/libft_ft_printf.a

#DIRECTORIES

INCLUDE		:=	include/

BUILD		:=	.build/

SRC			:=	src/

MODULES		:=	char/		\
				file/		\
				ft_lst/		\
				ft_printf/	\
				math/		\
				memory/		\
				num_string/	\
				string/		\
				write/		\

CHAR_DIR	:=	${BUILD}${SRC}char/

FILE_DIR	:=	${BUILD}${SRC}file/

FT_LST_DIR	:=	${BUILD}${SRC}ft_lst/

FT_PF_DIR	:=	${BUILD}${SRC}ft_printf/

MATH_DIR	:=	${BUILD}${SRC}math/

MEMORY_DIR	:=	${BUILD}${SRC}memory/

NUM_STR_DIR	:=	${BUILD}${SRC}num_string/

STRING_DIR	:=	${BUILD}${SRC}string/

WRITE_DIR	:=	${BUILD}${SRC}write/

#PREREQUISITES

MEMORY		:=	src/memory/ft_memset.c	\
				src/memory/ft_bzero.c	\
				src/memory/ft_memcpy.c	\
				src/memory/ft_memrcpy.c	\
				src/memory/ft_memmove.c	\
				src/memory/ft_memchr.c	\
				src/memory/ft_memcmp.c	\
				src/memory/ft_calloc.c	\

CHAR		:=	src/char/ft_isalpha.c		\
				src/char/ft_isdigit.c		\
				src/char/ft_isalnum.c		\
				src/char/ft_isascii.c		\
				src/char/ft_isprint.c		\
				src/char/ft_toupper.c		\
				src/char/ft_tolower.c		\
				src/char/ft_char_in_set.c	\

WRITE		:=	src/write/ft_putchar_fd.c	\
				src/write/ft_putstr_fd.c	\
				src/write/ft_putendl_fd.c	\
				src/write/ft_putnbr_fd.c	\

STRING		:= 	src/string/ft_strlen.c			\
				src/string/ft_strlcpy.c			\
				src/string/ft_strlcat.c			\
				src/string/ft_strchr.c			\
				src/string/ft_strrchr.c			\
				src/string/ft_strncmp.c			\
				src/string/ft_strnstr.c			\
				src/string/ft_strdup.c			\
				src/string/ft_substr.c			\
				src/string/ft_strjoin.c			\
				src/string/ft_strjoin_free.c	\
				src/string/ft_strtrim.c			\
				src/string/ft_split.c			\
				src/string/ft_strmapi.c			\
				src/string/ft_striteri.c		\
				src/string/ft_strchr_charset.c	\
				src/string/ft_free_strs.c		\

NUM_STRING	:=	src/num_string/ft_atoi.c		\
				src/num_string/ft_atol.c		\
				src/num_string/ft_itoa.c		\
				src/num_string/ft_ltoa.c		\
				src/num_string/ft_ultoa_base.c	\

MATH		:=	src/math/ft_power.c	\

FILE		:=	src/file/get_next_line.c	\
				src/file/gnl_utils.c		\
				src/file/get_all_line.c		\

FT_LST		:=	src/ft_lst/ft_lstnew.c		\
				src/ft_lst/ft_lstadd_front.c\
				src/ft_lst/ft_lstsize.c		\
				src/ft_lst/ft_lstlast.c		\
				src/ft_lst/ft_lstadd_back.c	\
				src/ft_lst/ft_lstdelone.c	\
				src/ft_lst/ft_lstclear.c	\
				src/ft_lst/ft_lstiter.c		\
				src/ft_lst/ft_lstmap.c		\

FT_PRINTF	:=	src/ft_printf/ft_printf.c			\
				src/ft_printf/ft_fprintf.c			\
				src/ft_printf/pf_utils.c			\
				src/ft_printf/pf_create_str.c		\
				src/ft_printf/pf_get_percentsc.c	\
				src/ft_printf/pf_parsing_arg.c		\
				src/ft_printf/pf_add_functions.c	\
				src/ft_printf/pf_get_number.c		\
				src/ft_printf/pf_get_xupperx.c		\

SRCS		:=	${MEMORY}		\
				${CHAR}			\
				${WRITE}		\
				${STRING}		\
				${NUM_STRING}	\
				${MATH}			\
				${FILE}			\
				${FT_LST}		\
				${FT_PRINTF}	\

#TARGETS

OBJS		:=	${SRCS:%.c=${BUILD}%.o}

DEPS		:=	${SRCS:%.c=${BUILD}%.d}

MEMORY_OBJ	:=	${MEMORY:%.c=${BUILD}%.o}

CHAR_OBJ	:=	${CHAR:%.c=${BUILD}%.o}

WRITE_OBJ	:=	${WRITE:%.c=${BUILD}%.o}

STRING_OBJ	:=	${STRING:%.c=${BUILD}%.o}

NUM_STR_OBJ	:=	${NUM_STRING:%.c=${BUILD}%.o}

MATH_OBJ	:=	${MATH:%.c=${BUILD}%.o}

FILE_OBJ	:=	${FILE:%.c=${BUILD}%.o}

FT_LST_OBJ	:=	${FT_LST:%.c=${BUILD}%.o}

FT_PF_OBJ	:=	${FT_PRINTF:%.c=${BUILD}%.o}

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
####	DECORATION						##

#TEXTE

INDENT		:=	[libft]:

TABS		:=

ifdef TAB
	INDENT	:= ${TAB}${INDENT}
	TABS	:= ${TAB}
endif

#COLORS

CCOMPILE	:=  \033[36m

CCREATE		:=  \033[95m

CDONE		:=  \033[5;32m

CFCLEAN		:=  \033[31m

CCLEAN		:=  \033[33m

NOCOLOR		 :=  \033[0m

##########################################
####	CUSTOM COMMANDS					##

RM			:= 	rm -f

MAKE		:=	@make -j --no-print-directory TAB="${TABS}" -C

##########################################
####	MANDATORY TARGET				##

all:		${NAME}

${NAME}:	memory char write string num_string file ft_lst ft_printf

clean:
			@${RM} -r ${BUILD}
			@echo "${CCLEAN}${INDENT} Removing object${NOCOLOR}"

fclean:		clean
			@${RM} ${NAME}
			@${RM} src/*/*.a
			@echo "${CFCLEAN}${INDENT} Removing ${NAME}${NOCOLOR}"

re:			fclean all

.PHONY:		all	clean fclean re

##########################################
####	MODULES TARGET					##

${BUILD}%.o: 	%.c
				@${CC} ${CFLAGS} -c ${CPPFLAGS} $< -o $@
				@echo "${CCOMPILE}${INDENT} Compiling $@${NOCOLOR}"

${BUILD}${SRC}:
				@mkdir -p ${BUILD}
				@mkdir -p ${addprefix ${BUILD}, ${SRC}}

-include ${DEPS}

#PRETTY NAME

memory:			${MEMORY_DIR} ${MEMORY_LIB}

${MEMORY_DIR}:	| ${BUILD}${SRC}
				@mkdir -p ${MEMORY_DIR}

char:			${CHAR_DIR} ${CHAR_LIB}

${CHAR_DIR}:	| ${BUILD}${SRC}
				@mkdir -p ${CHAR_DIR}

math:			${MATH_DIR} ${MATH_LIB}

${MATH_DIR}:	| ${BUILD}${SRC}
				@mkdir -p ${MATH_DIR}

write:			${WRITE_DIR} ${WRITE_LIB}

${WRITE_DIR}:	| ${BUILD}${SRC}
				@mkdir -p ${WRITE_DIR}

string:			memory char ${STRING_DIR} ${STRING_LIB}

${STRING_DIR}:	| ${BUILD}${SRC}
				@mkdir -p ${STRING_DIR}

num_string:		string ${NUM_STR_DIR} ${NUM_STR_LIB}

${NUM_STR_DIR}:	| ${BUILD}${SRC}
				@mkdir -p ${NUM_STR_DIR}

file:			write string ${FILE_DIR} ${FILE_LIB}

${FILE_DIR}:	| ${BUILD}${SRC}
				@mkdir -p ${FILE_DIR}

ft_lst:			memory ${FT_LST_DIR} ${FT_LST_LIB}

${FT_LST_DIR}:	| ${BUILD}${SRC}
				@mkdir -p ${FT_LST_DIR}

ft_printf:		write num_string ${FT_PF_DIR} ${FT_PF_LIB}

${FT_PF_DIR}:	| ${BUILD}${SRC}
				@mkdir -p ${FT_PF_DIR}

.PHONY:	memory char write string num_string file math ft_lst ft_printf

#LIBRARIES

${MEMORY_LIB}:	${MEMORY_OBJ}
				${MAKE} src/memory

${CHAR_LIB}:	${CHAR_OBJ}
				${MAKE} src/char

${MATH_LIB}:	${MATH_IBJ}
				${MAKE} src/math

${WRITE_LIB}:	${WRITE_OBJ}
				${MAKE} src/write

${STRING_LIB}:	${STRING_OBJ}
				${MAKE} src/string

${NUM_STR_LIB}:	${NUM_STR_OBJ}
				${MAKE} src/num_string

${FILE_LIB}:	${FILE_OBJ}
				${MAKE} src/file

${FT_LST_LIB}:	${FT_LST_OBJ}
				${MAKE} src/ft_lst

${FT_PF_LIB}:	${FT_PF_OBJ}	
				${MAKE} src/ft_printf
