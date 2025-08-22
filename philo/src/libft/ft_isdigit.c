/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:01:02 by marvin            #+#    #+#             */
/*   Updated: 2025/08/22 16:37:28 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/h_philo.h"

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
