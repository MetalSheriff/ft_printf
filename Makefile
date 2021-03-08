# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ypeckled <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 12:56:15 by ypeckled          #+#    #+#              #
#    Updated: 2021/01/24 20:53:55 by ypeckled         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME                =   libftprintf.a

CC                  =   gcc

CFLAGS              =   -Wall -Wextra -Werror

AR                  =   ar -rcs

RM                  =   rm -f

LIB_DIR             =   libft/

HEADER              =   ft_printf.h\

PRINTF_SRC          =   ft_input_data_processing.c\
                        ft_local_itoa_base.c\
                        ft_parser.c\
                        ft_print_character.c\
                        ft_print_converter.c\
                        ft_print_hexadecimal_integer.c\
                        ft_print_integer.c\
                        ft_print_percent.c\
                        ft_print_pointer.c\
                        ft_print_string.c\
                        ft_print_unsigned_integer.c\
                        ft_printf.c\
                        ft_reset.c\

SRCS                =   $(PRINTF_SRC)

OBJS	            =	$(SRCS:.c=.o)


.c.o:
			            $(CC) $(CFLAGS)	-I $(HEADER) -c $< -o $(<:.c=.o)

$(NAME):	            ${OBJS}
				        make -C $(LIB_DIR)
				        echo Compiling $(NAME)
				        cp $(LIB_DIR)libft.a ./$(NAME)
				        $(AR) $(NAME) $(OBJS)

all:		            $(NAME)

clean:
				        $(RM) $(OBJS)
				        make -C $(LIB_DIR) clean

fclean:             	clean
				        $(RM) $(NAME)
				        make -C $(LIB_DIR) fclean

debug:                  $(SRCS) ../main.c
						gcc -g $(SRCS) ../main.c -L libft/ -l ft -o debug

re:			            fclean all

.PHONY:                 clean fclean all re

