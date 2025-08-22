/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:00:35 by marvin            #+#    #+#             */
/*   Updated: 2025/08/17 15:07:24 by marvin           ###   ########.fr       */
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
	printf("%d %d %s\n", (get_current_time() - philo->info->start_time), philo->id,
		message);
	pthread_mutex_unlock(&philo->info->death_mtx);
}

void	eat(t_philo *philo)
{
	if (philo->info->num_of_philos == 1)
	{
		print_message(philo, "has taken a fork");
		usleep(philo->info->time_to_die);
		return ;
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, "has taken a fork");
	}
	print_message(philo, "is eating");
	pthread_mutex_lock(&philo->info->write_mtx);
	philo->last_meal_time = get_current_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->info->write_mtx);
	ft_usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep(philo->info->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_message(philo, "is thinking");
}
