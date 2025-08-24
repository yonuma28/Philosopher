/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:03:05 by marvin            #+#    #+#             */
/*   Updated: 2025/08/24 13:12:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/h_philo.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

// int main(void)
// {
//     if (isdigit('a'))
//         puts("a");
//     if (isdigit('4'))
//         puts("4");
//     if (ft_isdigit('a'))
//         puts("a");
//     if (ft_isdigit('4'))
//         puts("4");
// }
