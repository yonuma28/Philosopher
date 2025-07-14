/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:26:22 by marvin            #+#    #+#             */
/*   Updated: 2025/07/14 11:26:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <h_philo.h>

int main(int args, char *argv[])
{
    check_input(argv);
    if (init_program() == -1)
        return (clean_all(), 1);
    if (create_thread() == -1)
        return (clean_all(), 1);
    clean_all();
    return (0);    
}
