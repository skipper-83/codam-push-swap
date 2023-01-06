PUSH_SWAP_SRC_DIR	=	sources/ps
PUSH_SWAP_OBJ_DIR	=	objects/ps
CHECKER_SRC_DIR		=	sources/checker
CHECKER_OBJ_DIR		=	objects/checker
SHARED_SRC_DIR		=	sources/shared
SHARED_OBJ_DIR		=	objects/shared
GENERATOR_SRC_DIR	=	sources/generator
GENERATOR_OBJ_DIR	=	sources/generator
INCLUDE_DIR			=	headers

PUSH_SWAP_SRCS		=	$(wildcard $(PUSH_SWAP_SRC_DIR)/*.c)
PUSH_SWAP_OBJS		=	$(patsubst $(PUSH_SWAP_SRC_DIR)/%.c,$(PUSH_SWAP_OBJ_DIR)/%.o,$(PUSH_SWAP_SRCS))
CHECKER_SRCS		=	$(wildcard $(CHECKER_SRC_DIR)/*.c)
CHECKER_OBJS		=	$(patsubst $(CHECKER_SRC_DIR)/%.c,$(CHECKER_OBJ_DIR)/%.o,$(CHECKER_SRCS))
SHARED_SRCS			=	$(wildcard $(SHARED_SRC_DIR)/*.c)
SHARED_OBJS			=	$(patsubst $(SHARED_SRC_DIR)/%.c,$(SHARED_OBJ_DIR)/%.o,$(SHARED_SRCS))
GENERATOR_SRC		=	$(GENERATOR_SRC_DIR)/generator.c
GENERATOR_OBJ		=	$(patsubst $(GENERATOR_SRC_DIR)/%.c,$(GENERATOR_OBJ_DIR)/%.o,$(GENERATOR_SRC))

CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra

NAME				=	push_swap
CHECKER				=	checker
GENERATOR			=	generator
ENTRIES				=	10
LIBDIR				=	sources/libft
LIB					=	$(LIBDIR)/libft.a


RM					=	rm -f

all					: $(NAME)
#					@echo "\033[1mdone.\n\033[0m"

clean				:
					@echo "\033[1mCleaning\033[0m"
					@$(MAKE) -C $(LIBDIR) clean
					@$(RM) $(PUSH_SWAP_OBJS)
					@$(RM) $(GENERATOR_OBJS)
					@$(RM) $(SHARED_OBJS)
					@echo "\033[1mDone\033[0m"

fclean				: clean
					@echo "\033[1mCleaning all\033[0m"
					@$(MAKE) -C $(LIBDIR) fclean
					@$(RM) $(NAME)
					@$(RM) $(GENERATOR)
					@$(RM) $(CHECKER)
					@echo "\033[1mDone\033[0m"
					

re					: fclean all

start				:
					@echo "\n\033[1mMaking $(NAME)\033[0m\n\n"

run					: $(NAME) $(GENERATOR)
					$(eval ARG=$(shell ./$(GENERATOR) $(ENTRIES)))
					./$(NAME) $(ARG)

$(NAME)				: $(SHARED_OBJS) $(PUSH_SWAP_OBJS)  $(LIB)
					@echo "\nCompiling $(NAME)...   "
					@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) $(SHARED_OBJS) $(LIB) -o $(NAME)
					@echo "\033[1mdone.\n\033[0m"


$(CHECKER)			: $(SHARED_OBJS) $(CHECKER_OBJS) $(LIB)
					@echo "\nCompiling $(CHECKER)...   "
					@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(SHARED_OBJS) $(LIB) -o $(CHECKER)
					@echo "\033[1mdone.\n\033[0m"

$(GENERATOR) 		: $(GENERATOR_OBJ) $(LIB)
					@echo "\nCompiling $(GENERATOR)...\n"
					@$(CC) $(CFLAGS) $(GENERATOR_OBJ) $(LIB) -o $(GENERATOR)
					@echo "\033[1mdone.   \033[0m"

$(LIB)				:
					@echo Creating libft\n
					@$(MAKE) -C $(LIBDIR)

$(PUSH_SWAP_OBJ_DIR)/%.o: $(PUSH_SWAP_SRC_DIR)/%.c
					@echo "Creating push swap object:" $@"\x1b[1A\x1b[M"
					@mkdir -p $(PUSH_SWAP_OBJ_DIR)
					@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c -o $@ $<

$(CHECKER_OBJ_DIR)/%.o: $(CHECKER_SRC_DIR)/%.c
					@echo "Creating checker object:" $@"\x1b[1A\x1b[M"
					@mkdir -p $(CHECKER_OBJ_DIR)
					@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c -o $@ $<

$(SHARED_OBJ_DIR)/%.o: $(SHARED_SRC_DIR)/%.c 
					@echo "Creating shared object:" $@"\x1b[1A\x1b[M"
					@mkdir -p $(SHARED_OBJ_DIR)
					@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c -o $@ $<

$(GENERATOR_OBJ_DIR)/%.o: $(GENERATOR_SRC_DIR)/%.c 
					@echo "Creating generator object:" $@"\x1b[1A\x1b[M"
					@mkdir -p $(GENERATOR_OBJ_DIR)
					@$(CC) $(CFLAGS) -c -o $@ $<

.PHONY				: all clean fclean re run 