#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/15 23:06:36 by kcosta            #+#    #+#             *#
#*   Updated: 2016/11/17 14:07:39 by kcosta           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = halma
CC = gcc
FLAGS = -Wextra -Wall -Werror
SRCSPATH = srcs/
SRCS = halma.c display.c menu.c player.c game.c
OBJS = $(SRCS:.c=.o)

%.o: $(SRCSPATH)%.c
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

.PHONY: clean

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
