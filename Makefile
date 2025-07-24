# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 11:31:40 by marvin            #+#    #+#              #
#    Updated: 2025/07/23 16:32:35 by yonuma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = main.c
PHILO = philo
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I./include #-fsanitize=thread
FILES = monitor/monitor.c \
		prepare/check.c \
		prepare/init.c \
		thread/create_thread.c \
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