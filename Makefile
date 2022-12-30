PUSH_SWAP_SRC_DIR	=	sources
PUSH_SWAP_OBJ_DIR	=	objects
GENERATOR_SRC_DIR	=	sources/generator
GENERATOR_OBJ_DIR	=	sources/generator

PUSH_SWAP_SRCS		=	$(wildcard $(PUSH_SWAP_SRC_DIR)/*.c)
PUSH_SWAP_OBJS		=	$(patsubst $(PUSH_SWAP_SRC_DIR)/%.c,$(PUSH_SWAP_OBJ_DIR)/%.o,$(PUSH_SWAP_SRCS))
GENERATOR_SRC		=	$(GENERATOR_SRC_DIR)/generator.c
GENERATOR_OBJ		=	$(patsubst $(GENERATOR_SRC_DIR)/%.c,$(GENERATOR_OBJ_DIR)/%.o,$(GENERATOR_SRC))

CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra

NAME				=	push_swap
GENERATOR			=	generator
ENTRIES				=	10
LIBDIR				=	sources/libft
LIB					=	$(LIBDIR)/libft.a


RM					=	rm -f

all					: $(NAME)

clean				:
					$(MAKE) -C $(LIBDIR) clean
					$(RM) $(PUSH_SWAP_OBJS)

fclean				: clean
					$(MAKE) -C $(LIBDIR) fclean
					$(RM) $(NAME)

re					: fclean all

run					: $(NAME) $(GENERATOR)
					$(eval ARG=$(shell ./$(GENERATOR) $(ENTRIES)))
					./$(NAME) $(ARG)

$(NAME)				: $(PUSH_SWAP_OBJS) $(LIB)
					$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) $(LIB) -o $(NAME)

$(GENERATOR) 		: $(GENERATOR_OBJ) $(LIB)
					$(CC) $(CFLAGS) $(GENERATOR_OBJ) $(LIB) -o $(GENERATOR)

$(LIB)				:
					$(MAKE) -C $(LIBDIR)

$(PUSH_SWAP_OBJ_DIR)/%.o: $(PUSH_SWAP_SRC_DIR)/%.c 
					$(CC) $(CFLAGS) -c -o $@ $<

$(GENERATOR_OBJ_DIR)/%.o: $(GENERATOR_SRC_DIR)/%.c 
					$(CC) $(CFLAGS) -c -o $@ $<

.PHONY				: all clean fclean re run