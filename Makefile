SRCS =	sources/main.c \
		sources/map.c \
		sources/key_event.c \
		sources/mouse_event.c \
		sources/image.c \
		sources/render.c \
		sources/utils.c \
		sources/error.c \

SRCS_BONUS =	sources_bonus/main_bonus.c \
				sources_bonus/map_bonus.c \
				sources_bonus/key_event_bonus.c \
				sources_bonus/mouse_event_bonus.c \
				sources_bonus/image_bonus.c \
				sources_bonus/render_bonus.c \
				sources_bonus/utils_bonus.c \
				sources_bonus/error_bonus.c \
				sources_bonus/enemy_bonus.c

OBJS =	$(patsubst sources%, objects%, $(SRCS:.c=.o))
OBJS_BONUS = $(patsubst sources_bonus%, objects%, $(SRCS_BONUS:.c=.o))

CC =	cc -Wall -Wextra -Werror
NAME =	so_long
BONUS = so_long_bonus

INC =	-I./includes
LIB =	-L./libft -lft -L./mlx -lmlx
FRAMEWORK = -framework OpenGL -framework AppKit

LIBFT =	libft/libft.a
GNL_SRCS = 	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c
GNL_OBJS =	$(GNL_SRCS:.c=.o)

all : $(LIBFT) objects $(NAME)

bonus : $(LIBFT) objects $(BONUS)

$(LIBFT) :
	@echo " [ comipling libft... ] "
	@make -s -C libft bonus
	@echo " [ libft ready ] "

objects :
	@mkdir -p objects

# objects/%.o
$(NAME) : $(GNL_OBJS) $(OBJS)
	@$(CC) $^ $(LIB) $(FRAMEWORK) $(INC)/so_long.h -o $@
	@echo " [ so_long ready ] "

$(BONUS) : $(GNL_OBJS) $(OBJS_BONUS)
	@$(CC) $^ $(LIB) $(FRAMEWORK) $(INC)/so_long_bonus.h  -o $@
	@echo " [ so_long bonus ready] "

objects/%.o : sources/%.c
	@echo " [ comipling so_long... ]"
	@$(CC) -c $^ -o $@ $(INC)

objects/%.o : sources_bonus/%.c
	@echo " [ comipling so_long_bonus... ]"
	@$(CC) -c $^ -o $@ $(INC)

get_next_line/%.o : get_next_line/%.c
	@echo " [ comipling gnl... ]"
	@$(CC) -c $^ -o $@

clean :
	@echo " [ cleaning so_long... ]"
	@make clean -C libft
	@rm -f $(GNL_OBJS)
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo " [ so_long cleaned ] "

fclean :
	@echo " [ fcleaning so_long... ]"
	@make fclean -C libft
	@rm -f $(GNL_OBJS)
	@rm -f $(OBJS) $(OBJS_BONUS)
	@rm -f $(NAME) $(BONUS)
	@echo " [ so_long fcleaned ] "

re :
	make fclean
	make all

.PHONY: clean fclean re
