CC = cc
CFLAG = -Wall -Wextra -Werror -g
AR = ar -rcs
RM = rm -rf

SRCS = src/input_argv.c \
src/judgment.c \
src/push_swap.c \
src/doubly_linked_list.c \
src/command_push.c \
src/command_swap.c \
src/command_reverse.c \
src/command_double_reverse.c \
src/ft_atoi_re.c \
src/sand.c

OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIB = push_swap.a


all : $(NAME)

$(NAME) : $(LIB)
	make -C libft/
	make -C ft_printf/
	$(CC) $(CFLAG) -o $@ $^ -L libft/ -lft -L ft_printf/ -lftprintf

$(LIB) : $(OBJS)
	$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@
clean :
	make clean -C libft/
	make clean -C ft_printf/
	$(RM) $(OBJS)

fclean : 
	make fclean -C libft/
	make fclean -C ft_printf/
	$(RM) $(OBJS) $(NAME) $(LIB)

re : 
	make fclean
	make all

.PHONY: all clean fclean re
