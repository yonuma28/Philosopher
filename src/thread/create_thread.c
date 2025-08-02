/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:20:46 by marvin            #+#    #+#             */
/*   Updated: 2025/08/02 19:53:26 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <h_philo.h>

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->death_mtx);
	if ((philo->info->is_dead) == 1)
		return (pthread_mutex_unlock(&philo->info->death_mtx), 1);
	pthread_mutex_unlock(&philo->info->death_mtx);
	return (0);
}

void	*action_philo(void *_philo)
{
	t_philo	*philo;

	philo = (t_philo *)_philo;
	while (!dead_loop(philo))
	{
		eat(philo);
		sleeping(philo);
		think(philo);
	}
	return (NULL);
}

int	create_even_philos(t_info	*info, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < info->num_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, action_philo,
				&philos[i]) != 0)
		{
			while (i >= 0)
			{
				i -= 2;
				pthread_detach(philos[i].thread);
			}
			return (1);
		}
		i += 2;
	}
	return (0);
}

int	create_odd_philos(t_info	*info, t_philo *philos)
{
	int	i;

	i = 1;
	ft_usleep((unsigned int)info->time_to_eat);
	while (i < info->num_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, action_philo,
				&philos[i]) != 0)
		{
			while (i >= 1)
			{
				i -= 2;
				pthread_detach(philos[i].thread);
			}
			return (1);
		}
		i += 2;
	}
	return (0);
}

int	create_thread(t_info   *info, t_philo *philos)
{
	int			i;
	pthread_t	observer;

	i = 0;
	if (pthread_create(&observer, NULL, monitor, philos) != 0)
		return (write(STDERR_FILENO, "Pthread_create Error\n", 21), 1);
	if (create_even_philos(info, philos))
		return (write(STDERR_FILENO, "Pthread_create Error\n", 21), 1);
	if (create_odd_philos(info, philos))
		return (write(STDERR_FILENO, "Pthread_create Error\n", 21), 1);
	if (pthread_join(observer, NULL) != 0)
		return (1);
	i = 0;
	while (i < info->num_of_philos)
	{
		if (pthread_join(philos[i++].thread, NULL) != 0)
			return (1);
	}
	return (0);
}
