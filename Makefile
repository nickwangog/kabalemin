NAME = lem-in
LIBDIR = ./libft/libft.a
SRCDIR = ./srcs/
LIBDIR = ./libft/
OBJDIR = ./objs/
INCDIR = ./includes/
SRCFILES =	main.c \
			read.c \
			rooms.c \
			utilities.c \
			solve.c \
			links.c \
			sort.c \
			queue.c\
			move_ants.c \
			ant_lcm.c

OBJFILES =	$(SRCFILES:.c=.o)
SRCS        = $(addprefix $(SRCDIR), $(SRCFILES))
OBJ        = $(addprefix $(OBJDIR), $(OBJFILES))
LIBFT      = $(addprefix $(LIBDIR), libft.a)
FLAGS = -Wall -Werror -Wextra

all: obj $(LIBFT) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@gcc $(FLAGS) -I $(INCDIR) -o $@ -c $<

$(LIBFT):
	@make -C $(LIBDIR)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LIBFT)
	@echo "Butterhorn!"

clean:
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBDIR)

fclean:
	@make clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBDIR)

re:	
	@make fclean
	@make all

.PHONY: all clean fclean re
