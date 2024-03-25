# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 13:00:34 by timschmi          #+#    #+#              #
#    Updated: 2024/03/25 13:20:55 by timschmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line_utils.c get_next_line.c

OFILES = $(SRCS:.c=.o)

CC = cc

# CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=n
LDFLAGS= -L. -lgetnext

NAME = libgetnext.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)
	make clean

%: %.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OFILES)
	rm -f $(SRCS:.c=)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:  all clean fclean re