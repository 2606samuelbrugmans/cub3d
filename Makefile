NAME = cub3D
BONUS_NAME = cub3D_bonus

LIBFT = ./libft/libft.a
MLX = ./mlx_linux/libmlx_Linux.a

CC = gcc
CFLAGS = -Wall -Wextra -lm #-Werror # -o3 -fsanitize=address -g 

RM = rm -rf

SRC_DIR = src/
OBJ_DIR = obj/
BONUS_SRC_DIR = src_bonus/
BONUS_OBJ_DIR = obj_bonus/

SRC_FILES = main init_map parsing texture_parsing map_parsing game init_game cub3D_utils free_cub3D init_player ray ray_texture movements
BONUS_SRC_FILES =


OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR), $(addsuffix _bonus.o, $(BONUS_SRC_FILES)))
BONUS_SRC = $(addprefix $(BONUS_SRC_DIR), $(addsuffix _bonus.c, $(BONUS_SRC_FILES)))

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(BONUS_NAME)

$(LIBFT):
		make -C ./libft

$(MLX):
		make -C ./mlx_linux

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c
		mkdir -p $(BONUS_OBJ_DIR)
		$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

bonus:  $(MLX) $(BONUS_NAME)

clean:
		$(RM) ./libft/*.o
		$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
		$(RM) ./libft/libft.a
		$(RM) $(NAME) $(BONUS_NAME)

re: fclean all