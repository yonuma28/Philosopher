/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:26:22 by marvin            #+#    #+#             */
/*   Updated: 2025/07/26 20:28:38 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <h_philo.h>

int main(int args, char *argv[])
{
    t_info      info;
    t_philo     *philos;
    t_mtx       *forks;

    if (!(args == 5 || args == 6))
        return (write(STDERR_FILENO, "usage: 5 900 300 300 5\n", 23), 1);
    check_input(argv);
    if (init_program(&info, &philos, &forks, argv) == 1)
        return (clean_all(&info, philos, forks), 1);
    if (create_thread(&info, philos) == 1)
        return (clean_all(&info, philos, forks), 1);
    clean_all(&info, philos, forks);
    return (0);
}
