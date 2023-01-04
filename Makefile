NAME				= 	pipex

NAME_BONUS			= 	pipex_bonus

SRCS				=	main_pipex.c pipex.c get_next_line.c get_next_line_utils.c ft_split.c ft_strtrim.c ft_strlcpy.c ft_substr.c ft_strncmp.c ft_strlen.c ft_strdup.c ft_strjoin.c  tools.c get_paths.c check_args.c

SRCS_BONUS			=	main_bonus.c pipex.c get_next_line.c get_next_line_utils.c ft_split.c ft_strtrim.c ft_strlcpy.c ft_substr.c ft_strncmp.c ft_strlen.c ft_strdup.c ft_strjoin.c  tools.c get_paths.c check_args.c

CC					= 	cc

CFLAGS				=	-Wall -Wextra -Werror

all					:  ${NAME}

bonus				:  ${NAME_BONUS}

${NAME}				:  ${SRCS}
						${CC} ${CFLAGS} ${SRCS} -o ${NAME}

${NAME_BONUS}		:  ${SRCS_BONUS}
						${CC} ${CFLAGS} ${SRCS_BONUS} -o ${NAME_BONUS}

clean				:
						rm -f ${NAME}

fclean				:  clean
						rm -f ${NAME_BONUS}

re 					: 	fclean all 