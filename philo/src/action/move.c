/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:00:35 by marvin            #+#    #+#             */
/*   Updated: 2025/09/14 12:01:10 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/h_philo.h"

void	print_message(t_philo *philo, char *message)
{
	if (dead_loop(philo))
		return ;
	pthread_mutex_lock(&philo->info->write_mtx);
	if (dead_loop(philo))
	{
		pthread_mutex_unlock(&philo->info->write_mtx);
		return ;
	}
	printf("%ld %d %s\n", (get_current_time() - philo->info->start_time),
		philo->id, message);
	pthread_mutex_unlock(&philo->info->write_mtx);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		// ft_usleep(10, philo);
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork");
	}
	else
	{
		if (philo->info->num_of_philos % 2 != 0)
		{
			ft_usleep((philo->id - 1) *
				(philo->info->time_to_eat / philo->info->num_of_philos), philo);
		}
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, "has taken a fork");
	}
}

void	eat(t_philo *philo)
{
	if (philo->info->num_of_philos == 1)
	{
		print_message(philo, "has taken a fork");
		ft_usleep(philo->info->time_to_die, philo);
		return ;
	}
	take_forks(philo);
	if (dead_loop(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	print_message(philo, "is eating");
	pthread_mutex_lock(&philo->info->eat_mtx);
	philo->last_meal_time = get_current_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->info->eat_mtx);
	ft_usleep(philo->info->time_to_eat, philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep(philo->info->time_to_sleep, philo);
}

void	think(t_philo *philo)
{
	print_message(philo, "is thinking");
}
