# #=== OS detecter ==
OS			= $(shell uname -s)
# #==================

# #=== wish flags to use to compile depending on the os ====
ifeq ($(OS), Darwin)
	MLX_O = -Imlx -c -o3
	MLXCC = -lmlx -framework OpenGL -framework AppKit
else
	MLX_O = -I/usr/include -Imlx_linux -o3 -c
	MLXCC = -Lmlx_linux -lmlx_Linux -L/usr/lib/ -Imlx_linux -lXext -lX11 -lm
endif
# #=========================================================

# #=== Colors ===
NO_COLOR    =   \033[0m
GRAY = \033[0;1;90m
RED = \033[0;1;91m
GREEN = \033[0;1;92m
# #==============

# #=== Standard ===
NAME		= fdf
B_NAME		= fdf_bonus
SRC_DIR		= src/
B_SRC_DIR	= b_src/
OBJ_DIR		= obj/
B_OBJ_DIR	= b_obj/
LIBFT		= include/my_lib/libft.a
SRC_FILES	= main map_utils map_utils2 fdf_utils drawing_utils drawing_utils2 bresnham_algo
B_SRC_FILES	= main_bonus map_utils_bonus map_utils2_bonus keys_bonus mous_bonus menu_bonus fdf_utils_bonus drawing_utils_bonus drawing_utils2_bonus bresnham_algo_bonus
# #================

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
B_SRC 		= 	$(addprefix $(B_SRC_DIR), $(addsuffix .c, $(B_SRC_FILES)))
B_OBJ 		= 	$(addprefix $(B_OBJ_DIR), $(addsuffix .o, $(B_SRC_FILES)))
CFLAGS = -g -o3 -Wall -Wextra -Werror -g -fsanitize=address
CC = cc 
OBJF		=	.cache_exists
B_OBJF		=	.b_cache_exists


all : $(NAME)
	@printf "$(GREEN)ALL DONE NOTHING TO BE MADE$(NO_COLOR)"

# # == Rule that compile source files into object files ==
$(OBJ_DIR)%.o	: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) $(MLX_O) $< -o $@
	@printf "$(GRAY)\rcompiling...$(NO_COLOR)"
# #=======================================================
$(B_OBJ_DIR)%.o	: $(B_SRC_DIR)%.c | $(B_OBJF)
	$(CC) $(CFLAGS) $(MLX_O) $< -o $@
	@printf "$(GRAY)\rcompiling...$(NO_COLOR)"
# #=======================================================

# #=== rule that compile the final program ===
$(NAME) : $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(MLXCC) $(LIBFT) -o $(NAME)
	@printf "$(GREEN)\r   ---> FDF IS MADE <---      \n$(NO_COLOR)"

bonus	: $(LIBFT) $(B_OBJ) 
	@$(CC) $(CFLAGS) $(B_OBJ) $(MLXCC) $(LIBFT) -o $(B_NAME)
	@printf "$(GREEN)\r   ---> FDF_BONUS IS MADE <---      \n$(NO_COLOR)"
# #===========================================

# #== creat bonus part ===
$(LIBFT)	:	include/my_lib
	@make -C include/my_lib
# #=======================


# #== rule that called if object folder doesn't exist ==
$(OBJF):
	@mkdir -p $(OBJ_DIR)
$(B_OBJF):
	@mkdir -p $(B_OBJ_DIR)
# #=====================================================


# # == rule deleting compiled files : the cache folder ==
clean :
	@rm -rf $(OBJ_DIR)
	@rm -rf $(B_OBJ_DIR)
	@make clean -C include/my_lib
	@printf "$(RED)-->   CLEANED   <--$(NO_COLOR)"
# # =====================================================

# # == Rule calling clean and deleting the final file ==
fclean	:	clean
	@make fclean -C include/my_lib
	@rm -f $(NAME) $(B_NAME)
# # ====================================================

re		:	fclean all

