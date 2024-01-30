#::::::::::::::::OS::::::::::::::::#
OS 			= $(shell uname -s)

#:::::::::::::::VARS:::::::::::::::#
SRC_DIR		= src/
OBJ_DIR 	= .obj/
LIB			= lib/lib.a
FSANITIZE 	= #-g -fsanitize=address
CFLAGS 		= -Wall -Werror -Wextra $(HEADER) $(FSANITIZE)
CC 			= cc

#:::::::::::::::MANDATORY:::::::::::::::#
NAME 		= cub3D
HEADER = -I mandatory/includes
MAIN = main ft_janitor 
M_OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(addprefix mandatory/src/, $(MAIN))))

#:::::::::::::::BONUS:::::::::::::::#
BONUS 		= cub3D_bonus
HEADER = -I bonus/includes
MAIN_B = main_bonus ft_janitor_bonus 
M_OBJS_B = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(addprefix bonus/src/, $(MAIN_B))))

#::::::::::::::::MLX:::::::::::::::#
ifeq ($(OS), Darwin)
COMP 		= -lmlx -framework OpenGL -framework AppKit
COMP_O 		= -Imlx
else
COMP 		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
COMP_O 		= -I/usr/include -Imlx_linux
endif

all: $(NAME)

bonus: $(BONUS)

#::::::::::::::::PRS:::::::::::::::#
P_FILES = file_check texter_check colors_check map_check0 map_check1 ft_error m_get_next_line new_map
			#---mandatory---#
P_OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(addprefix mandatory/src/parsing/, $(P_FILES))))
			#---bonus---#
P_FILES_B = file_check_bonus texter_check_bonus colors_check_bonus map_check0_bonus map_check1_bonus \
			ft_error_bonus m_get_next_line_bonus new_map_bonus
P_OBJS_B = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(addprefix bonus/src/parsing/, $(P_FILES_B))))

#::::::::::::::::RAY:::::::::::::::#
			#---mandatory---#
R_FILES = ft_shapes ft_drawer ft_keylogger ft_maths_hub0 ft_maths_hub1 ft_starter ft_rays \
		  ft_player_movements ft_canvas_control
R_OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(addprefix mandatory/src/ray_casting/, $(R_FILES))))

			#---bonus---#
R_FILES_B = ft_shapes_bonus ft_drawer_bonus ft_keylogger_bonus ft_maths_hub0_bonus ft_maths_hub1_bonus \
			ft_starter_bonus ft_rays_bonus ft_player_movements_bonus ft_canvas_control_bonus ft_bonus_stuff

R_OBJS_B = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(addprefix bonus/src/ray_casting/, $(R_FILES_B))))

#::::::::::::::::TXT:::::::::::::::#
			#---mandatory---#
T_FILES_M = ft_textures
T_OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(addprefix mandatory/src/textures/, $(T_FILES_M))))

			#---bonus---#
T_FILES_B =  ft_textures_bonus ft_textures_selection_bonus
T_OBJS_B = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(addprefix bonus/src/textures/, $(T_FILES_B))))

#:::::::::::::Compile::::::::::::::#
			#---mandatory---#
$(NAME): $(M_OBJS) $(P_OBJS) $(R_OBJS) $(T_OBJS)
	@echo $(cursive)$(grey)":::Making object files:::"$(reset)
	@echo $(cursive)$(grey)":::Compiling $(NAME):::"$(reset)
	@$(CC) $(CFLAGS) $(M_OBJS)  $(P_OBJS) $(R_OBJS) $(T_OBJS) $(LIB) $(COMP) -o $(NAME)
	@echo $(f_green)":::✅ $(NAME) is ready ✅:::"$(reset)

			@#---bonus---#
$(BONUS): $(M_OBJS_B) $(P_OBJS_B) $(R_OBJS_B) $(T_OBJS_B)
	@echo $(cursive)$(grey)":::Making object files:::"$(reset)
	@echo $(cursive)$(grey)":::Compiling $(BONUS):::"$(reset)
	@$(CC) $(CFLAGS) $(M_OBJS_B) $(P_OBJS_B) $(R_OBJS_B) $(T_OBJS_B) $(LIB) $(COMP) -o $(BONUS)
	@echo $(f_green)":::✅ $(BONUS) is ready ✅:::"$(reset)

$(OBJ_DIR)%.o: %.c 
	@make -s -C lib/
	@mkdir -p .obj/mandatory/src .obj/mandatory/src/parsing .obj/mandatory/src/ray_casting .obj/mandatory/src/textures
	@mkdir -p .obj/bonus/src .obj/bonus/src/parsing .obj/bonus/src/ray_casting .obj/bonus/src/textures
	@$(CC) $(CFLAGS) $(COMP_O) -c $< -o $@

#:::::::::::::Clean::::::::::::::#
clean:
	@echo $(cursive)$(grey)":::Deleting object files:::"$(reset)
	@rm -rf $(OBJ_DIR)
	@make -s clean -C lib/
	@echo $(red)":::Deleted:::"$(reset)

fclean: clean
	@echo $(cursive)$(grey)":::Deleting executable:::"$(reset)
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@make -s fclean -C lib/
	@echo $(red)":::Deleted:::"$(reset)

re: fclean all

.PHONY: all clean fclean re os

#::::::::::::::Colors::::::::::::::#
black  		= "\033[0;30m"
red    		= "\033[0;31m"
green  		= "\033[0;32m"
f_green		= "\e[92;5;118m"
yellow 		= "\033[0;33m"
purple		= "\033[0;35m"
blue   		= "\033[0;34m"
cyan  		= "\033[0;36m"
grey   		= "\033[0;90m"
reset  		= "\033[0m"

#::::::::::::::Fonts:::::::::::::::#
bold     	= "\033[1m"
cursive    	= "\033[3m"
underline 	= "\033[4m"
