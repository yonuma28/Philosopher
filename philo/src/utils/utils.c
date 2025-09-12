/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:34:43 by marvin            #+#    #+#             */
/*   Updated: 2025/09/11 13:10:07 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/h_philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void ft_usleep(size_t milliseconds, t_philo *philo)
{
    size_t start_time;

    start_time = get_current_time();
    while ((get_current_time() - start_time) < milliseconds)
    {
        if (dead_loop(philo))
            break;
        usleep(500);
    }
}
