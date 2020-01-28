# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 11:51:30 by javrodri          #+#    #+#              #
#    Updated: 2020/01/28 18:53:21 by javrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d.a

SRCS 		=  imput_keys.c \
				initialize.c \
				main.c \
				raycasting.c \
				utils.c 	\
				walk_movement.c \
				get_next_line.c \
				map_reader.c \
				ft_atoi.c \
				ft_itoa.c \
				ft_putstr.c \
				utils_2.c \
				get_next_line_utils.c \
				map_position.c \
				textures.c \
				draw.c 

all: $(NAME)
			


$(NAME) : $(SRCS) cub3d.h
			#-@clear
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit
1:			
			#-@clear
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map1.cub"

2:			
			#-@clear
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map2"

3:			
			#-@clear
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map3.cub"
			
clean:
			-@$(RM) $(OBJS) 

fclean: clean
			-@$(RM) $(NAME)
		

re: 		fclean all