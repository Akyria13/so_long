########################################################################################################################
#                                                      VARIABLES                                                       #
########################################################################################################################

AUTHOR			:=		jowagner
NAME			:= 		so_long

AR				:= 		ar -rcs
CC				:= 		cc
CFLAGS			:= 		-Wall -Wextra -Werror -MD -MP -g3 -Iinc/
MLX_FLAGS		:=		-lXext -lX11 -lm -lz


SRC				:=		src/main.c \
						src/initialization/free_map.c \
						src/initialization/initialization.c \
						src/initialization/read_file.c \
						src/mlx/sprite_init.c \
						src/parsing/check_file_extension.c \
						src/parsing/flood_fill.c \
						src/parsing/is_map_empty.c \
						src/parsing/is_map_have_wall.c \
						src/parsing/is_map_rectangular.c \
						src/parsing/is_map_too_high.c \
						src/parsing/is_map_valid_format.c \
						src/parsing/parsing_initialization.c \
						src/parsing/remove_newline.c \
						src/player/display_count.c \
						src/player/element_position.c \
						src/player/init_element.c \
						src/player/player_moove.c \
						src/player/render_player.c \
						src/player/render_env.c \
						src/window/close_window.c \
						src/window/init_so_long.c \
						src/window/put_tiles.c \
						src/window/window_size.c \

########################################################################################################################
#                                                      DIRECTORY                                                       #
########################################################################################################################

INC_PATH		:=		inc/
SRC_PATH		:=		src/
OBJ_DIR			:= 		obj/
LIBFT_DIR		:=		libft/
LIBFT			:= 		$(LIBFT_DIR)libft.a
MLX 			:= 		./minilibx-linux

OBJ             := 		$(SRC:$(SRC_PATH)%.c=$(OBJ_DIR)%.o)

#OBJ_BONUS 		:= 		$(SRC_BONUS:%.c=$(OBJ_DIR)%.o)
DEP				:=		$(OBJ:%.o=%.d)

-include $(DEP)

########################################################################################################################
#                                                      TARGETS                                                         #
########################################################################################################################

all : 					.print_header lib $(NAME)

lib :
							@$(MAKE) --silent -C $(LIBFT_DIR)

clean :					.print_header
							@printf "%-50b%b" "  $(YELLOW)[so_long/$(OBJ_DIR)] :$(RESET)" "\n"
							@rm -rf $(OBJ_DIR)
							@printf "%-50b%b" "  => $(BOLD_RED)Clean$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							@printf "\n"
							@printf "%-50b%b" "  $(YELLOW)[$(LIBFT_DIR)obj] :$(RESET)" "\n"
							@$(MAKE) --silent -C $(LIBFT_DIR) clean
							@printf "%-50b%b" "  => $(BOLD_RED)Clean$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							@printf "\n"

fclean : 				clean
							@rm -f $(NAME)
							@$(MAKE) --silent -C $(LIBFT_DIR) fclean
							@printf "%-50b%b" "  $(YELLOW)[$(NAME)] :$(RESET)" "\n"
							@printf "%-50b%b" "  => $(BOLD_RED)Clean$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							@$(MAKE) --silent -C $(MLX) clean > /dev/null 2>&1
							@printf "%-50b%b" "\n  $(YELLOW)[$(MLX)] :$(RESET)" "\n"
							@printf "%-50b%b" "  => $(BOLD_RED)Clean$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							$(call SEPARATOR)

re : 					.print_header fclean all $(LIBFT) $(NAME)

debug :
							@printf "Checking source file paths : "
							@printf "SRC_PATH = $(SRC_PATH)"
							@ls -la $(SRC_PATH)
							@printf "Main.c exist ? $(shell test -f $(SRC_PATH)main.c && echo 'YES' || echo 'NO')\n"
							@printf "DIR_PATH_INIT = $(DIR_PATH_INIT)"
							@ls -la $(DIR_PATH_INIT)
							@printf "Free_map.c exist ? $(shell test -f $(DIR_PATH_INIT)free_map.c && echo 'YES' || echo 'NO')"

.print_header :
							$(call TITLE)
							$(call SEPARATOR)
							$(call BUILD)
							$(call SEPARATOR)


########################################################################################################################
#                                                       COMMANDS                                                       #
########################################################################################################################

$(NAME) 			: 	$(OBJ) $(LIBFT)
							@$(MAKE) --silent -C $(MLX) > /dev/null 2>&1
							@printf "%-50b%b" "  $(YELLOW)[MLX] :$(RESET)" "\n"
							@printf "%-50b%b" "  => $(BOLD_GREEN)Created$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							@printf "%-50b%b" "\n  $(YELLOW)[$(NAME)] :$(RESET)" "\n"
							@printf "%-50b%b" "  => $(BOLD_GREEN)Created$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							@$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)/libmlx.a $(MLX_FLAGS)
							$(call SEPARATOR)

$(OBJ_DIR)%.o		:	 $(SRC_PATH)%.c $(INC_PATH)so_long.h | $(OBJ_DIR)
							@mkdir -p $(dir $@)
							@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(LIBFT_DIR) -c $< -o $@

$(OBJ_DIR)			:
							@printf "%-50b%b" "  $(YELLOW)[so_long/$(OBJ_DIR)] :$(RESET)" "\n"
							@printf "%-50b%b" "  => $(BOLD_GREEN)Created$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							@mkdir -p $(OBJ_DIR)
							@mkdir -p $(OBJ_DIR)initialization/
							@mkdir -p $(OBJ_DIR)mlx/
							@mkdir -p $(OBJ_DIR)parsing/
							@mkdir -p $(OBJ_DIR)player/
							@mkdir -p $(OBJ_DIR)window/
							@printf "\n"

########################################################################################################################
#                                                      DISPLAY                                                         #
########################################################################################################################

MAGENTA			:=		\033[0;95m
YELLOW			:=		\033[1;93m
GREEN 			:=		\033[0;32m
BLUE			:=		\033[0;94m
RED 			:=		\033[0;31m

BOLD_YELLOW 	:=		\e[1;33m
BOLD_PURPLE		:=		\e[1;35m
BOLD_GREEN		:= 		\e[1;32m
BOLD_WHITE		:=		\e[1;37m
BOLD_CYAN 		:= 		\e[1;36m
BOLD_BLUE 		:= 		\e[1;34m
BOLD_RED 		:=		\e[1;31m

RESET 			:=		\033[0m

define	TITLE
						@echo "$(MAGENTA)---------------------------------------------------$(RESET)";
						@echo "$(BOLD_RED)                    _                   "
						@echo "$(BOLD_RED)       ___  ___    | | ___  _ __   __ _ "
						@echo "$(BOLD_YELLOW)      / __|/ _ \   | |/ _ \| '_ \ / _' |"
						@echo "$(BOLD_GREEN)      \__ \ (_) |  | | (_) | | | | (_| |"
						@echo "$(BOLD_BLUE)      |___/\___/$(BOLD_PURPLE)___$(BOLD_BLUE)|_|\___/|_| |_|\__, |"
						@echo "$(BOLD_PURPLE)              |_____|             $(BOLD_BLUE)|___/"
endef

define PROGRESS_BAR

						@echo -n "$(BOLD_YELLOW)["
						@i=1; while [ $$i -le 3 ]; do echo -n "$(BOLD_WHITE)."; sleep 0.2; i=$$((i + 1)); done
						@echo -n "$(BOLD_YELLOW)]"
endef


define	BUILD
						@printf "%-32b%b" "  $(BOLD_CYAN)AUTHOR :$(RESET)" "$(BOLD_WHITE)$(AUTHOR)$(RESET)\n";
						@printf "%-32b%b" "  $(BOLD_CYAN)NAME   :$(RESET)" "$(BOLD_WHITE)$(NAME)$(RESET)\n";
						@printf "%-32b%b" "  $(BOLD_CYAN)CC     :$(RESET)" "$(BOLD_WHITE)$(CC)$(RESET)\n";
						@printf "%-32b%b" "  $(BOLD_CYAN)FLAGS  :$(RESET)" "$(BOLD_WHITE)$(CFLAGS)$(RESET)\n";
endef

define	SEPARATOR
						@printf "\n"
						@echo "$(MAGENTA)---------------------------------------------------$(RESET)";
						@printf "\n"
endef

########################################################################################################################
#                                                       PHONY TARGETS                                                  #
########################################################################################################################

.PHONY : 				all lib bonus clean fclean re
