/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:20:46 by marvin            #+#    #+#             */
/*   Updated: 2025/07/23 17:08:07 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <h_philo.h>

int	create_even_philos(t_info *info, t_philo	**philos);

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
