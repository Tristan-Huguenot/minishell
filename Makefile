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

SRC0	:=	parsing/		\
			linked_list/	\
			builtin/		\
			prompt/			\
			pipe/			\
			init/			\
			error/			\
			exit/			\
			files/			\
			signal/			\
			cmd/

#PREREQUISITES

INIT	:=	src/init/init_param.c					\
			src/init/init_plots.c					\
			src/init/init_childs.c					\
			src/init/init_pipe.c					\

LD_LIST	:=	src/linked_list/list_env.c				\
			src/linked_list/list_plots.c			\
			src/linked_list/list_utils.c			\
			src/linked_list/list_size.c				\

EXIT	:=	src/exit/exit_program.c					\
			src/exit/close_fd.c						\
			src/exit/close_heredoc_fd.c				\
			src/exit/force_close_fd.c				\
			src/exit/exit_child.c					\

FILES	:=	src/files/files_compute.c				\
			src/files/handle_redir.c				\
			src/files/handle_here_doc.c				\
			src/files/check_redir.c					\

ERROR	:=	src/error/error_handler_cmd.c			\
			src/error/error_handler.c				\

PARSING	:=	src/parsing/parsing.c					\
			src/parsing/parsing_utils.c				\
			src/parsing/parsing_arg.c				\
			src/parsing/parsing_redir.c				\
			src/parsing/parsing_redir_move.c		\
			src/parsing/wrong_quote.c				\
			src/parsing/parsing_variable.c			\
			src/parsing/parsing_var_tab.c			\
			src/parsing/parsing_variable_utils.c	\
			src/parsing/parsing_var_utils.c			\
			src/parsing/is_separator.c				\
			src/parsing/remove_quote.c				\

PROMPT	:=	src/prompt/prompt.c						\
			src/prompt/need_execution.c				\
			src/prompt/need_execution_utils.c		\

BUILTIN	:=	src/builtin/utils.c						\
			src/builtin/env.c						\
			src/builtin/export.c					\
			src/builtin/export_utils.c				\
			src/builtin/unset.c						\
			src/builtin/echo.c						\
			src/builtin/pwd.c						\
			src/builtin/exit.c						\
			src/builtin/cd.c						\
			src/builtin/cd_utils.c					\

SIGNAL	:=	src/signal/signal.c						\
			src/signal/signal_utils.c				\

CMD		:=	src/cmd/child_execve.c					\
			src/cmd/dup_fd.c						\
			src/cmd/read_lost_pipe.c				\

SRCS	:=	src/main.c								\
			${INIT}									\
			${LD_LIST}								\
			${EXIT}									\
			${FILES}								\
			${ERROR}								\
			${PARSING}								\
			${PROMPT}								\
			${BUILTIN}								\
			${SIGNAL}								\
			${CMD}									\

#TARGETS

OBJS	:=	${SRCS:%.c=${BUILD}%.o}

DEPS	:=	${SRCS:%.c=${BUILD}%.d}

##########################################
####	FLAGS							##

CC			:=	clang

CFLAGS		:=	-Werror -Wextra -Wall

ifdef DEBUG
	ifeq (${DEBUG}, 1)
		CFLAGS +=  -g
	endif
	ifeq (${DEBUG}, 2)
		CFLAGS +=  -gdwarf-4
	endif
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
	MAKE := ${MAKE} DEBUG=${DEBUG} -C
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

clean:		rmtags
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
			${MAKE} ${dir ${LIBFT}} ft_printf file

.PHONY:	libraries ${LIBFT}

##########################################
####	CTAGS							##

CTAGS_FILE	:=	${SRCS}										\
				${shell ls ${dir ${LIBFT}}src/*/*.c}		\
				${shell ls ${INCLUDE}*.h}					\
				${shell ls ${dir ${LIBFT_D}}${INCLUDE}*.h}	\

tags:		${CTAGS_FILE}
			@ctags ${CTAGS_FILE}
			@echo "${CCTAGS}${INDENT} Making $@${NOCOLOR}"

rmtags:
			@${RM} tags
			@echo "${CCLEAN}${INDENT} Deleting ctags${NOCOLOR}"

.PHONY:		ctags
