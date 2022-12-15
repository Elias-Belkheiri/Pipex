NAME		= 	pipex

LIB			=	libpipe.a

SRCS		=	ft_split.c ft_strtrim.c ft_strlcpy.c ft_substr.c ft_strncmp.c ft_strlen.c ft_strdup.c ft_strjoin.c ft_split_pipex.c

OBJS		= 	$(SRCS:.c=.o)

CC			= 	cc

CFLAGS		=	-Wall -Wextra -Werror

all			: ${NAME}

${NAME}		: ${LIB}
				${CC} ${CFLAGS} pipex.c ${LIB} -o ${NAME} -fsanitize=address

${LIB}		: ${OBJS}
				ar -rc ${LIB} ${OBJS}

${OBJS}		: ${SRCS}
				${CC}  ${CFLAGS} -c ${SRCS}

clean		:
				rm -f $(OBJS)

fclean		: clean
				rm -f ${LIB} 

re 			: 	fclean all 