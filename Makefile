# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lshellie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 19:27:10 by lshellie          #+#    #+#              #
#    Updated: 2019/04/20 16:12:04 by lshellie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFILE = *.c

OFILE = *.o

HFILE = libft.h

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -I $(HFILE) -c $(CFILE)
	ar rc $(NAME) $(OFILE)
	ranlib $(NAME)

clean: 
	/bin/rm -f $(OFILE)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
