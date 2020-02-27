# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 15:50:28 by mbourand          #+#    #+#              #
#    Updated: 2020/01/17 18:45:49 by mbourand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS			= ft_atoi.c    ft_drawshotgun.c  ft_init.c    ft_jump.c    ft_movement.c     ft_raycasting.c   ft_screenshot.c   ft_textures.c \
ft_cub3d.c ft_error.c ft_isdigit.c ft_keyboard.c     ft_movement2.c  ft_sprites.c ft_get_next_line.c ft_calloc.c ft_bzero.c  ft_get_spec2.c \
ft_draw_gmaeover.c ft_hud.c   ft_itoa.c  ft_memcpy.c  ft_raycaastinb.c  ft_strncmp.c  ft_get_spec.c ft_check_map.c ft_get_next_line_utils.c 
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			=  -Wall -Wextra -Werror -I.
LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
MLX				= mlx

NAME			= cub3D

all:			$(NAME)

$(NAME):		 $(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
				@$(MAKE) -C mlx clean
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re