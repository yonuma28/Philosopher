/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:18:41 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 11:57:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <h_philo.h>


static bool is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->write_mtx);
	if ((get_current_time() - philo->last_meal_time) > philo->info->time_to_die)
	{
		pthread_mutex_unlock(&philo->info->write_mtx);
		return (true);
	}
	pthread_mutex_unlock(&philo->info->write_mtx);
	return (false);
}

static void set_philo_dead(t_philo *philo)
{
    pthread_mutex_lock(&philo->info->death_mtx);
    philo->info->is_dead = true;
    printf("%d %d died\n", get_current_time() - philo->info->start_time, philo->id);
    pthread_mutex_unlock(&philo->info->death_mtx);
}

static bool check_all_ate(t_philo *philos)
{
    int i;
    int satisfied_philos;

    i = 0;
    satisfied_philos = 0;
    if (philos->info->num_times_to_eat == -1)
        return (false);
    pthread_mutex_lock(&philos->info->write_mtx);
    while (i < philos->info->num_of_philos)
    {
        if (philos[i].meal_count >= philos->info->num_times_to_eat)
            satisfied_philos++;
        i++;
    }
    pthread_mutex_unlock(&philos->info->write_mtx);
    if (satisfied_philos == philos->info->num_of_philos)
    {
        pthread_mutex_lock(&philos->info->death_mtx);
        philos->info->is_dead = true;
        pthread_mutex_unlock(&philos->info->death_mtx);
        return (true);
    }
    return (false);
}

void    *monitor(void   *args)
{
    t_philo *philos;
    int i;

    philos = (t_philo *)args;
    while (1)
    {
        i = 0;
        while (i < philos->info->num_of_philos)
        {
            if (is_dead(&philos[i]))
            {
                set_philo_dead(&philos[i]);
                return (NULL);
            }
            i++;
        }
        if (check_all_ate(philos))
            break;
		if (philos->info->is_dead == true)
            break;
    }
    return (philos);
}
