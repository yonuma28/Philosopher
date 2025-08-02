/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:34:43 by marvin            #+#    #+#             */
/*   Updated: 2025/08/02 17:32:15 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <h_philo.h>

size_t	get_current_time(void)
{
	struct timeval	time;

	write(1, "bbbb\n", 5);
	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(size_t msec)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < msec)
		usleep(500);
	write(1, "aaaaaa\n", 7);
	return (0);
}