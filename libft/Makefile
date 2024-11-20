# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artemii <artemii@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 17:39:46 by azakharo          #+#    #+#              #
#    Updated: 2024/11/10 19:23:19 by artemii          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Добавляем все файлы из основной папки и extra_functions
SOURCES =	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strndup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_substr.c	\
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_realloc.c \
			extra_functions/ft_printf/ft_printf.c \
			extra_functions/ft_printf/print_functions.c \
			extra_functions/get_next_line/get_next_line.c \
			extra_functions/get_next_line/get_next_line_utils.c

# Преобразуем c-файлы в объектные
OBJECTS = ${SOURCES:.c=.o}

# Указываем компилятор, флаги и команды
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIB = ar rcs

# Правило для компиляции .c файлов в .o
.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I.

# Основная цель для сборки библиотеки
all: ${NAME}

${NAME}: ${OBJECTS}
	${LIB} ${NAME} ${OBJECTS}

# Команды очистки объектных файлов и библиотеки
clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

# Пересобрать библиотеку
re: fclean all
