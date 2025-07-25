# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 11:31:40 by marvin            #+#    #+#              #
#    Updated: 2025/07/25 15:40:28 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = main.c
PHILO = philo
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I./include #-fsanitize=thread
FILES = monitor/monitor.c \
		prepare/check.c \
		prepare/init.c \
		clean/clean.c \
		action/move.c \
		thread/create_thread.c \
		utils/utils.c \
		main.c
SRCS = $(addprefix ./src/, $(FILES))
OBJS = $(SRCS:.c=.o)

all: $(PHILO)

$(PHILO): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRCS:.c=.o)

fclean: clean
	$(RM) $(PHILO)

re: fclean all

.PHONY : all clean fclean re