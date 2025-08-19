/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:18:41 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 11:28:08 by marvin           ###   ########.fr       */
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
		if (philos->info->is_dead == true) //|| check_all_ate(philos)
            break;
    }
    return (philos);
}
