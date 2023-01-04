PUSH_SWAP_SRC_DIR	=	sources/ps
PUSH_SWAP_OBJ_DIR	=	objects/ps
SHARED_SRC_DIR		=	sources/shared
SHARED_OBJ_DIR		=	objects/shared
GENERATOR_SRC_DIR	=	sources/generator
GENERATOR_OBJ_DIR	=	sources/generator
INCLUDE_DIR			=	headers

PUSH_SWAP_SRCS		=	$(wildcard $(PUSH_SWAP_SRC_DIR)/*.c)
PUSH_SWAP_OBJS		=	$(patsubst $(PUSH_SWAP_SRC_DIR)/%.c,$(PUSH_SWAP_OBJ_DIR)/%.o,$(PUSH_SWAP_SRCS))
SHARED_SRCS			=	$(wildcard $(SHARED_SRC_DIR)/*.c)
SHARED_OBJS			=	$(patsubst $(SHARED_SRC_DIR)/%.c,$(SHARED_OBJ_DIR)/%.o,$(SHARED_SRCS))
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
					@$(MAKE) -C $(LIBDIR) clean
					@$(RM) $(PUSH_SWAP_OBJS)
					@$(RM) $(GENERATOR_OBJS)
					@$(RM) $(SHARED_OBJS)

fclean				: clean
					@$(MAKE) -C $(LIBDIR) fclean
					@$(RM) $(NAME)

re					: fclean all

run					: $(NAME) $(GENERATOR)
					$(eval ARG=$(shell ./$(GENERATOR) $(ENTRIES)))
					./$(NAME) $(ARG)

$(NAME)				: $(SHARED_OBJS) $(PUSH_SWAP_OBJS)  $(LIB)
					@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) $(SHARED_OBJS) $(LIB) -o $(NAME)

$(GENERATOR) 		: $(GENERATOR_OBJ) $(LIB)
					@$(CC) $(CFLAGS) $(GENERATOR_OBJ) $(LIB) -o $(GENERATOR)

$(LIB)				:
					@echo Creating libft
					@$(MAKE) -C $(LIBDIR)

$(PUSH_SWAP_OBJ_DIR)/%.o: $(PUSH_SWAP_SRC_DIR)/%.c
					@echo Create: $@"\x1b[1A\x1b[M"
					@mkdir -p $(PUSH_SWAP_OBJ_DIR)
					@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c -o $@ $<

$(SHARED_OBJ_DIR)/%.o: $(SHARED_SRC_DIR)/%.c 
					@echo Create: $@"\x1b[1A\x1b[M"
					@mkdir -p $(SHARED_OBJ_DIR)
					@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c -o $@ $<

$(GENERATOR_OBJ_DIR)/%.o: $(GENERATOR_SRC_DIR)/%.c 
					@echo Create: $@"\x1b[1A\x1b[M"
					@mkdir -p $(GENERATOR_OBJ_DIR)
					@$(CC) $(CFLAGS) -c -o $@ $<

.PHONY				: all clean fclean re run