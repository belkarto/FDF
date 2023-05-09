# #=============================== OS detecter ==================================
OS			= $(shell uname -s)
# #==============================================================================

# #============= wish flags to use to compile depending on the os ===============
ifeq ($(OS), Darwin)
	MLX_O = -Imlx -c -o3
	MLXCC = -lmlx -framework OpenGL -framework AppKit
	NAME		= fdf
	SRC_DIR		= src/
else
	NAME		= fdf_linux
	SRC_DIR		= src_linux/
	MLX_O = -I/usr/include -Imlx_linux -o3 -c
	MLXCC = -Lmlx_linux -lmlx_Linux -L/usr/lib/ -Imlx_linux -lXext -lX11 -lm
endif
# #==============================================================================

# #=================================== Colors ===================================
NO_COLOR    = \033[0m
GRAY 		= \033[0;1;3;90m
RED 		= \033[0;1;3;91m
GREEN		= \033[0;1;3;92m
GREEN_L		= \033[0;1;3;36m
YELLOW		= \033[0;1;3;33m
BLUE		= \033[0;1;3;34m
# #==============================================================================

# #================================ Standard ====================================
OBJ_DIR		= obj/
LIBFT		= include/my_lib/libft.a
SRC_FILES	= main map_utils map_utils2 keys mous menu fdf_utils drawing_utils \
			  drawing_utils2 bresnham_algo
# #==============================================================================

AUTHOR		= 	belkarto
SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
CFLAGS = -g -O3 -Wall -Wextra -Werror -march=native -funroll-loops 
#-g -fsanitize=address
CC = gcc 
OBJF		=	.cache_exists


all : header $(NAME)

# #============== Rule that compile source files into object files ============
$(OBJ_DIR)%.o	: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) $(MLX_O) $< -o $@
	@printf "$(GRAY)\rcompiling...$(NO_COLOR)"
# #==============================================================================

# #==================== rule that compile the final program =====================
$(NAME) : $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(MLXCC) $(LIBFT) -o $(NAME)
	@printf "$(GREEN)\r- Fdf is ready ✅🥳 \n$(NO_COLOR)"
# #==============================================================================

# #=============================== creat bonus part =============================
$(LIBFT)	:	include/my_lib
	@make -C include/my_lib
# #==============================================================================


# #================== rule that called if object folder doesn't exist ===========
$(OBJF):
	@mkdir -p $(OBJ_DIR)
# #==============================================================================


# # =============== rule deleting compiled files : the cache folder =============
clean : header
	@rm -rf $(OBJ_DIR)
	@make clean -C include/my_lib
	@printf "$(RED)-->   CLEANED   <--$(NO_COLOR)"
# #==============================================================================

# # =================== Rule calling clean and deleting the final file ==========
fclean	:	clean
	@make fclean -C include/my_lib
	@rm -f $(NAME)
# #==============================================================================

re		:	fclean all

header	:
	@echo "$(GREEN)"
	@echo "███████╗██████╗ ███████╗"
	@echo "██╔════╝██╔══██╗██╔════╝"
	@echo "█████╗  ██║  ██║█████╗  "
	@echo "██╔══╝  ██║  ██║██╔══╝  "
	@echo "██║     ██████╔╝██║     "
	@echo "╚═╝     ╚═════╝ ╚═╝     "
	@printf  "$(GREEN_L)Author\t: $(BLUE)$(AUTHOR)\n"
	@printf  "$(GREEN_L)CC    \t: $(YELLOW)$(CC)\n\033[m"
	@printf  "$(GREEN_L)Flags \t: $(YELLOW)$(CFLAGS)\n\033[m"
	@echo
	@echo "$(NO_COLOR)"
# #==============================================================================
                        
