NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/main.c\
		src/parser.c\
		src/utils.c\
		src/exec/execution.c\
		src/exec/execution_cmd_simp.c\
		src/exec/redirections.c\
		src/exec/execution_utils_2.c\
		src/exec/ft_envp_cherch_bonus.c\
		src/exec/error_exit_utils.c\
		src/exec/error_exit_utils_2.c\
		src/builtin/exec_builtin.c\
		src/builtin/echo.c\
		src/builtin/exit.c\
		src/builtin/pwd.c\
		src/builtin/env_var_parser.c \
		src/builtin/export_var.c \
		src/builtin/print_envp.c \
		src/builtin/unset_var.c 

OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
INCLUDES = -I include -I libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

$(LIBFT):
	@make -C libft

clean:
	rm -f $(OBJS)
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all
	