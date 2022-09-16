# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 17:00:14 by nkim              #+#    #+#              #
#    Updated: 2022/09/16 13:21:11 by nkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= cub3D
NAME_BONUS				= cub3D_bonus

CC						= cc
CFLAGS					= -Wall -Werror -Wextra
AR						= ar rcs
RM						= rm -rf

LIBFT_DIR				= ./lib/libft/
LIBFT_INC				= -I $(LIBFT_DIR)/include
LIBFT_FLAGS				= -L ./$(LIBFT_DIR) -lft $(LIBFT_INC)

MLX_DIR					= ./lib/mlx/
MLX_INC					= -I $(MLX_DIR)
MLX_FLAGS				= -L ./$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit $(MLX_INC)

INCS_DIR				= ./include/
INCS_DIR_BONUS			= ./include_bonus/

INCS					= -I include
INCS_BONUS				= -I include_bonus

SRC_MAIN_DIR			= main/
SRC_MAIN				= $(addprefix $(SRC_MAIN_DIR), main.c)

SRC						= $(SRC_MAIN)

SRCS_DIR				= ./src/
SRCS_DIR_BONUS			= ./src_bonus/
SRCS					= $(addprefix $(SRCS_DIR), $(SRC))
SRCS_BONUS				= $(addprefix $(SRCS_DIR_BONUS), $(SRC))

OBJS					= $(SRCS:.c=.o)
OBJS_BONUS				= $(SRCS_BONUS:.c=.o)

.c.o :
	@$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(INCS_DIR_BONUS) -o $@ -c $?
	@echo $(CUT)$(BOLD)$(MINT) Compiling with $(CFLAGS)...$(RESET)
	@echo $(CUT)$(MAUVE) [$(notdir $^)] to [$(notdir $@)] $(RESET)
	@printf $(UP)$(UP)

$(NAME) : $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INCS_DIR) $(LIBFT_FLAGS) $(MLX_FLAGS)
	@printf $(CUT)$(CUT)
	@echo $(BOLD)$(L_PURPLE) ✨ $(NAME) ✨ $(GREEN)is ready 🎉 $(RESET)

all : $(NAME)

clean :
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@printf $(CUT)$(CUT)
	@$(RM) $(OBJS) $(OBJS_BONUS) so_long.dSYM

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) $(NAME_BONUS) so_long.dSYM
	@printf $(CUT)$(CUT)
	@echo $(BOLD)$(L_PURPLE) ✨ $(NAME) ✨ $(PINK)has been cleaned....🗑️$(RESET)

re : fclean
	@make all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT_FLAGS) -I $(INCS_DIR_BONUS) -L $(MLX_DIR) $(MLX_FLAGS)
	@printf $(CUT)$(CUT)
	@echo $(BOLD)$(L_PURPLE) ✨ $(NAME_BONUS) ✨ $(GREEN)is ready 🎉 $(RESET)

bonus_re : fclean
	@make bonus

test :
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) -g3 -o $(NAME) $(SRCS) $(LIBFT_FLAGS) -I $(INCS_DIR) -L $(MLX_DIR) $(MLX_FLAGS)

leak :
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) -g3 -fsanitize=address -o $(NAME) $(SRCS) $(LIBFT_FLAGS) -I $(INCS_DIR) -L $(MLX_DIR) $(MLX_FLAGS)

bonus_leak :
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) -g3 -fsanitize=address -o $(NAME_BONUS) $(SRCS_BONUS) $(LIBFT_FLAGS) -I $(INCS_DIR_BONUS) -L $(MLX_DIR) $(MLX_FLAGS)

norm :
	@norminette $(SRCS) $(INCS_DIR)*.h

PHONY	: all clean fclean re bonus

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