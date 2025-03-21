# ================== VARIABLES ==================
# Nom de l'exécutable
NAME = gnl.a

# Dossier contenant les fichiers sources
SRC_DIR = sources

# Liste des fichiers source
SRCS = $(SRC_DIR)/get_next_line.c \
	$(SRC_DIR)/get_next_line_utils.c

OBJS =		$(SRCS:.c=.o)

# Compilation
CC		=		gcc
FLAGS	=		-Wall -Werror -Wextra
RM		=		rm -f

# ================== REGLES ==================
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

# Compilation des fichiers .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re