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

# ここ修正してね
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I./include

SRCS = src/monitor/monitor.c \
       src/prepare/check.c \
       src/prepare/init.c \
       src/clean/clean.c \
       src/action/move.c \
       src/thread/create_thread.c \
       src/utils/utils.c \
       src/main.c

OBJS = $(SRCS:.c=.o)
TARGET = philo

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re