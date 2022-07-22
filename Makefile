SRCS	=	cub.c						\
			main.c						\
			srcs/get_next_line.c		\
			srcs/get_next_line_utils.c	\
			srcs/parsings.c				\
			srcs/map_parse.c			\
			srcs/map_parse_sec.c		\
			srcs/elements_parse.c		\
			engine/ws_engine.c			\
			engine/draw.c				\
			engine/rays.c				\
			engine/exit_cub.c			\
			engine/keys.c				\
			engine/utils_0.c			\
			engine/utils_1.c			\
			engine/sprites.c			\
			engine/sprite_cycle.c		\
			engine/frees.c				\
			bmp_conv.c					\

CC		=	clang

FLAG	=	-Wall -Wextra -Werror -g2 -I./includes/

NAME	=	cub3D

OBJS	=	${SRCS:.c=.o}

.c.o:
				$(CC) $(FLAG) -c $< -o $(<:.c=.o)

MAP		=	maps/map.cub

VALF	=	--tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes --log-file=valgrind_log

LNAME	=	libft.a

LPATH	=	./libft

all: ${LNAME} ${NAME} 

${NAME}	:	${LNAME}	${OBJS}
				${CC} ${FLAG} -lbsd -lm -lX11 -lXext ${OBJS} -o ${NAME} libmlx.a ${LNAME}

${LNAME}:
				rm -f ${LNAME}
				make -C ${LPATH} all
				cp ${LPATH}/${LNAME} .

clean	: 
				make -C ${LPATH} clean
				rm -f ${OBJS}

fclean	:	clean
				make -C ${LPATH} fclean
				rm -f ${NAME}
				rm -f ${LNAME}

no_flag	:	
			${CC} -lbsd -lm -lX11 -lXext ${SRCS} -o ${NAME} libmlx.a ${LNAME}

re		:	fclean all

test	:	all
				./${NAME} ${MAP}

leaks	:
				valgrind ${VALF} ./${NAME} ${MAP}
				grep -A1 "valgrind" valgrind_log | grep ${NAME} || echo -n

Phony: all clean fclean test re leaks

