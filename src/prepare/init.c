/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:48:49 by marvin            #+#    #+#             */
/*   Updated: 2025/07/23 20:32:12 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <h_philo.h>

int malloc_philos(t_info    *info, t_philo   *philos[], t_mtx   *forks[])
{
    *philos = (t_philo  *)malloc(sizeof(t_philo) * info->num_of_philos);
    if (!(*philos))
        return (write(STDERR_FILENO, "malloc error.\n", 14), 1);
    *forks = (t_mtx	*)malloc(sizeof(t_mtx) * info->num_of_philos);
	if (!(*forks))
        return (write(STDERR_FILENO, "malloc error.\n", 14), 1);
}

int	init_forks(t_info	*info, t_mtx	*forks[])
{
	int	i;

	i = 0;
	while (i < info->num_of_philos)
	{
		if (pthread_mutex_error(&forks[i], NULL) != 0)
			return (write(STDERR_FILENO, "Mutex Error.\n", 13), 1);
		i ++;
	}
	return (0);
}

void	set_philos(t_philo	**philo, t_info	*info, t_mtx	*forks[], char	*argv[])
{
	int	i;

	i = 0;
	while (i < info->num_of_philos)
	{
		philo[i]->id = i + 1;
		philo[i]->meal_count = 0;
		philo[i]->status = 0;
		philo[i]->right_fork = &forks[i];
		if (i == 0)
			philo[i]->left_fork = &forks[philo[i]->info->num_of_philos - 1];
		else
			philo[i]->left_fork = &forks[i - 1];
		i++;
	}
}

int init_program(t_info	*info, t_philo	*philos[], t_mtx	*forks[], 
	char	*argv[])
{
    info->num_of_philos = ft_atol(argv[1]);
    info->is_dead = false;
    if (malloc_philos(&info, &philos, &forks))
		return (1);
	if (init_forks(&info, &forks))
		return (1);
	set_philos(&philos, &info, &forks, argv);
	if (pthread_mutex_init(&info->write_mtx, NULL) != 0)
		return (write(STDERR_FILENO, "Mutex Error\n", 12), 1);
	if (pthread_mutex_init(&info->death_mtx, NULL) != 0)
		return (write(STDERR_FILENO, "Mutex Error\n", 12), 1);
    return (0);
}
