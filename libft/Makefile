SRCS	=	\
			ft_memcpy.c			\
			ft_memset.c			\
			ft_bzero.c			\
			ft_memmove.c		\
			ft_memccpy.c		\
			ft_memchr.c			\
			ft_strlen.c			\
			ft_memcmp.c			\
								\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_tolower.c		\
			ft_toupper.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strncmp.c		\
			ft_strlcpy.c		\
			ft_strlcat.c		\
			ft_strnstr.c		\
			ft_atoi.c			\
			ft_calloc.c			\
			ft_strdup.c			\
								\
			ft_substr.c			\
			ft_strjoin.c		\
			ft_strtrim.c		\
			ft_strmapi.c		\
			ft_split.c			\
			ft_itoa.c			\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
								\
			ft_iswhitespace.c	\

BNS		=	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c


INCL	=	-I\

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror

HEAD	=	libft.h

HEADB	=	libft_bonus.h

OBJS	=	${SRCS:.c=.o}

OBJB	=	${BNS:.c=.o}

NAME	=	libft.a

.c.o:
				$(CC) $(FLAG) -c $< -o $(<:.c=.o)

all:	$(NAME)

${NAME}:	${OBJS}
				ar rc ${NAME} ${OBJS}
				ranlib	${NAME}

clean:
				rm -f ${OBJS}
				rm -f ${OBJB}

fclean:			clean
				rm -f ${NAME}

re:				fclean all

bonus:		${OBJB}
				ar rc ${NAME} ${OBJB}
				ranlib ${NAME}

.PHONY:	all clean fclean re bonus
