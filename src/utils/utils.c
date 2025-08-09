/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:34:43 by marvin            #+#    #+#             */
/*   Updated: 2025/08/09 19:47:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <h_philo.h>

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(size_t msec)
{
	size_t	start;

	start = get_current_time();
	write(1, "bbbb\n", 5);
	while ((get_current_time() - start) < msec)
		usleep(500);
	write(1, "aaaaaa\n", 7);
	return (0);
}