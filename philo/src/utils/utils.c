/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:34:43 by marvin            #+#    #+#             */
/*   Updated: 2025/09/11 13:09:22 by yonuma           ###   ########.fr       */
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

int	ft_usleep(size_t msec, t_philo *philo)
{
	size_t	start;
	size_t	end_time;
	size_t	remain_time;

	start = get_current_time();
	end_time = start + msec;
	while (1)
	{
		pthread_mutex_lock(&philo->info->death_mtx);
		if (philo->info->is_dead == true)
		{
			pthread_mutex_unlock(&philo->info->death_mtx);
			break;
		}
		pthread_mutex_unlock(&philo->info->death_mtx);
		remain_time = end_time - get_current_time();
		if (remain_time <= 0)
			break ;
		usleep(remain_time);
	}
	return (0);
}
