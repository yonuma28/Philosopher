/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:48:49 by marvin            #+#    #+#             */
/*   Updated: 2025/09/14 16:48:06 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/h_philo.h"

int	malloc_philos(t_info *info, t_philo *philos[], t_mtx *forks[])
{
	*philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philos);
	if (!(*philos))
		return (write(STDERR_FILENO, "malloc error.\n", 14), 1);
	*forks = (t_mtx *)malloc(sizeof(t_mtx) * info->num_of_philos);
	if (!(*forks))
		return (write(STDERR_FILENO, "malloc error.\n", 14), 1);
	return (0);
}

int	init_forks(t_info *info, t_mtx *forks)
{
	int	i;

	i = 0;
	while (i < info->num_of_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (write(STDERR_FILENO, "Mutex Error\n", 12), 1);
		i++;
	}
	return (0);
}

void	input_data(t_info *info, char **argv)
{
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->start_time = get_current_time();
	if (argv[5])
		info->num_times_to_eat = ft_atoi(argv[5]);
	else
		info->num_times_to_eat = -1;
}

void	set_philos(t_philo *philo, t_info *info, t_mtx *forks)
{
	int	i;

	i = 0;
	while (i < info->num_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].info = info;
		philo[i].meal_count = 0;
		philo[i].status = 0;
		philo[i].last_meal_time = info->start_time;
		philo[i].right_fork = &forks[i];
		if (i + 1 == info->num_of_philos)
			philo[i].left_fork = &forks[0];
		else
			philo[i].left_fork = &forks[i + 1];
		i++;
	}
}

int	init_program(t_info *info, t_philo *philos[], t_mtx **forks, char *argv[])
{
	info->num_of_philos = ft_atoi(argv[1]);
	info->is_dead = false;
	input_data(info, argv);
	if (pthread_mutex_init(&info->death_mtx, NULL) != 0)
	{
		return (write(STDERR_FILENO, "Mutex Error (death_mtx init)\n", 29), 1);
	}
	if (pthread_mutex_init(&info->eat_mtx, NULL) != 0)
		return (write(STDERR_FILENO, "Mutex Error\n", 12), 1);
	if (pthread_mutex_init(&info->write_mtx, NULL) != 0)
		return (write(STDERR_FILENO, "Mutex Error\n", 12), 1);
	if (malloc_philos(info, philos, forks))
		return (1);
	if (init_forks(info, *forks))
		return (1);
	info->forks = *forks;
	set_philos(*philos, info, *forks);
	return (0);
}
