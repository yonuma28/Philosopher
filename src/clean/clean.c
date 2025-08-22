/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:53:43 by marvin            #+#    #+#             */
/*   Updated: 2025/07/24 13:53:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <h_philo.h>

void    clean_all(t_info *info, t_philo *philos, t_mtx  *forks)
{
    int i;

    i = 0;
    if (forks)
    {
        while (i < info->num_of_philos)
        {
            pthread_mutex_destroy(&forks[i]);
            i++;
        }
        free(forks);
    }
    pthread_mutex_destroy(&info->death_mtx);
    pthread_mutex_destroy(&info->write_mtx);
    if (philos)
        free(philos);
}
