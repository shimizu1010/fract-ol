SRCS	=  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
           ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
           ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
           ft_memcmp.c ft_strnstr.c ft_atoi.c \
           ft_calloc.c ft_strdup.c \
           ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
           ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS    = ${SRCS:.c=.o}

INCS    = includes

NAME    = libft.a

LIBC    = ar rc

CC        = cc
CFLAGS    = -Wall -Wextra -Werror

RM        = rm -f

# .c.o：ソースコードをオブジェクトファイルに変換する
# オブジェクトファイルに変換する
# -c：コンパイルのみを行い、リンクは行わない
# -o ${<:.c=.o}：出力ファイルの名前を指定
# -I ${INCS}：インクルードディレクトリを指定
.c.o:
	${CC} ${CFLAGS} -c -I ${INCS} $< -o ${<:.c=.o}

# ${NAME} ：ターゲットと同様に、${OBJS} から ${NAME} を生成する
${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all