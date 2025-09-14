/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:49:43 by marvin            #+#    #+#             */
/*   Updated: 2025/09/14 12:14:55 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/h_philo.h"

int	check_input(int args, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < args)
	{
		j = 0;
		if (argv[i] == NULL || argv[i][0] == '\0' || argv[i][0] == '0')
			return (1);
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}
