NAME					= cub3D

CC						= cc
ifdef DEBUG
	CFLAGS		= -g3 -fsanitize=address
else ifdef LEAKS
	CFLAGS		= -g
else
	CFLAGS 		= -Wall -Wextra -Werror
endif

AR						= ar rcs
RM						= rm -rf

LIBFT_DIR				= ./lib/libft/
LIBFT_INC				= -I$(LIBFT_DIR)/include
LIBFT_FLAGS				= -L./$(LIBFT_DIR) -lft

MLX_DIR					= ./lib/mlx/
MLX_INC					= -I$(MLX_DIR)
MLX_FLAGS				= -L./$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

INCS_DIR				= ./include/
INCS					= -I$(INCS_DIR)

SRC_TEST_DIR			= __test__/
SRC_TEST				= $(addprefix $(SRC_TEST_DIR), map.c)

SRC_UTIL_DIR			= util/
SRC_UTIL				= $(addprefix $(SRC_UTIL_DIR), ft_get_line.c \
														ft_trim_line.c \
														ft_strtrim_back.c \
														ft_make_img.c \
														ft_put_img.c \
							 							ft_str_to_rgb.c \
														ft_get_valid_rgb.c)

SRC_PARSE_DIR			= parse/
SRC_PARSE				= $(addprefix $(SRC_PARSE_DIR), parse.c \
														parse_map_info.c \
														parse_graphic_info.c \
														parse_state.c \
														valid_extension.c \
														valid_map.c \
														valid_edge_wall.c \
														valid_inner_wall.c)

SRC_HANDLER_DIR			= handler/
SRC_HANDLER				= $(addprefix $(SRC_HANDLER_DIR), keypress_handler.c)

SRC_ERROR_DIR			= error/
SRC_ERROR				= $(addprefix $(SRC_ERROR_DIR), throw_error.c)

SRC_DRAW_DIR			= draw/
SRC_DRAW				= $(addprefix $(SRC_DRAW_DIR), draw.c \
														draw_minimap.c \
														draw_line.c)

SRC_MINIMAP_DIR			= minimap/
SRC_MINIMAP				= $(addprefix $(SRC_MINIMAP_DIR), minimap.c)

SRC_RAYCAST_DIR			= raycast/
SRC_RAYCAST				= $(addprefix $(SRC_RAYCAST_DIR), raycast.c)

SRC_INIT_DIR			= init/
SRC_INIT				= $(addprefix $(SRC_INIT_DIR), init.c \
														init_state.c \
														init_info.c)

SRC_MAIN_DIR			= main/
SRC_MAIN				= $(addprefix $(SRC_MAIN_DIR), main.c)

SRC						= $(SRC_MAIN) \
							$(SRC_TEST) \
							$(SRC_PARSE) \
							$(SRC_HANDLER) \
							$(SRC_DRAW) \
							$(SRC_ERROR) \
							$(SRC_MINIMAP) \
							$(SRC_UTIL)	\
							$(SRC_RAYCAST) \
							$(SRC_INIT)

SRCS_DIR				= ./src/
SRCS					= $(addprefix $(SRCS_DIR), $(SRC))

OBJS					= $(SRCS:.c=.o)

.c.o :
	@$(CC) $(CFLAGS) $(INCS) $(LIBFT_INC) $(MLX_INC) -o $@ -c $?
	@echo $(CUT)$(BOLD)$(MINT) Compiling with $(CFLAGS)...$(RESET)
	@echo $(CUT)$(MAUVE) [$(notdir $^)] to [$(notdir $@)] $(RESET)
	@printf $(UP)$(UP)

$(NAME) : $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_FLAGS) $(MLX_FLAGS)
	@printf $(CUT)$(CUT)
	@echo $(BOLD)$(L_PURPLE) ✨ $(NAME) ✨ $(GREEN)is ready 🎉 $(RESET)

.PHONY	: all
all		: $(NAME)

.PHONY	: clean
clean	:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@$(RM) $(OBJS) $(NAME).dSYM
	@echo $(BOLD)$(MAUVE) 🗒 object files $(PINK)have been cleaned....🗑️$(RESET)


.PHONY	: fclean
fclean	: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo $(BOLD)$(L_PURPLE) ✨ $(NAME) ✨ $(PINK)has been cleaned....🗑️$(RESET)


.PHONY	: cc
cc 		: $(NAME) $(SOURCES)

.PHONY	: re
re		: fclean all

.PHONY	: debug
debug	:
	@make DEBUG=1 all

.PHONY	: leaks
leaks	:
	@make LEAKS=1 all

######################### Color #########################
GREEN="\033[32m"
MINT="\033[38;5;51m"
L_PURPLE="\033[38;5;55m"
MAUVE="\033[38;5;147m"
PINK="\033[38;5;175m"
RESET="\033[0m"
BOLD="\033[1m"
UP = "\033[A"
DOWN = "\033[B"
RIGHT = "\033[C"
LEFT = "\033[D"
CUT = "\033[K"
SAVE = "\033[s"
RESTORE = "\033[u"
