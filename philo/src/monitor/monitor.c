/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:18:41 by marvin            #+#    #+#             */
/*   Updated: 2025/09/14 18:04:51 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/h_philo.h"

static int	check_and_set_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->eat_mtx);
	if ((get_current_time() - philo->last_meal_time)
		>= philo->info->time_to_die)
	{
		pthread_mutex_unlock(&philo->info->eat_mtx);
		pthread_mutex_lock(&philo->info->death_mtx);
		philo->info->is_dead = true;
		pthread_mutex_unlock(&philo->info->death_mtx);
		pthread_mutex_lock(&philo->info->write_mtx);
		printf("%ld %d died\n", get_current_time() - philo->info->start_time,
			philo->id);
		pthread_mutex_unlock(&philo->info->write_mtx);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->eat_mtx);
	return (0);
}

static int	check_all_ate(t_philo *philos)
{
	int	i;
	int	satisfied_philos;

	i = 0;
	satisfied_philos = 0;
	if (philos->info->num_times_to_eat == -1)
		return (0);
	while (i < philos->info->num_of_philos)
	{
		pthread_mutex_lock(&philos[i].info->eat_mtx);
		if (philos[i].meal_count >= philos->info->num_times_to_eat)
			satisfied_philos++;
		pthread_mutex_unlock(&philos[i].info->eat_mtx);
		i++;
	}
	if (satisfied_philos == philos->info->num_of_philos)
	{
		pthread_mutex_lock(&philos->info->death_mtx);
		if (!philos->info->is_dead)
			philos->info->is_dead = true;
		pthread_mutex_unlock(&philos->info->death_mtx);
		return (1);
	}
	return (0);
}

void	*monitor(void *args)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)args;
	while (1)
	{
		i = 0;
		while (i < philos->info->num_of_philos)
		{
			if (check_and_set_death(&philos[i]))
				return (NULL);
			i++;
		}
		if (check_all_ate(philos))
			return (NULL);
		usleep(500);
	}
	return (NULL);
}
