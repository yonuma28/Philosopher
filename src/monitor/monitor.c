/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:18:41 by marvin            #+#    #+#             */
/*   Updated: 2025/07/23 14:18:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <h_philo.h>


void    *monitor(void   *args)
{
    t_philo *philos;

    philos = (t_philo *)args;
    while (1)
    {
        if (philos->info->is_dead == true) //|| check_all_ate(philos)
            break;
    }
    return (philos);
}
