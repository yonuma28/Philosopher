/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:00:35 by marvin            #+#    #+#             */
/*   Updated: 2025/07/26 12:26:11 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <h_philo.h>

void	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->info->death_mtx);
	if (philo->info->is_dead)
	{
		pthread_mutex_unlock(&philo->info->death_mtx);
		return ;
	}
	printf("%ld %d %s\n", (get_current_time() - philo->info->start_time), philo->id,
		message);
	pthread_mutex_unlock(&philo->info->death_mtx);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, "has taken a fork");
	if (philo->info->num_of_philos == 1)
	{
		usleep(philo->info->time_to_die);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, "has taken a fork");
	print_message(philo, "is eating");
	pthread_mutex_lock(&philo->info->write_mtx);
	philo->info->start_time = get_current_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->info->write_mtx);
	usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	print_message(philo, "is sleeping");
	usleep(philo->info->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_message(philo, "is thinking");
}
