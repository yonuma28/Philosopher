#ifndef H_PHILO_H
 # define H_PHILO_H
 # define   THINK   0b00000001
 # define   EAT     0b00000010
 # define   SLEEP   0b00000100
 # include <stdio.h>
 # include <stdlib.h>
 # include <pthread.h>
 # include <stdbool.h>

typedef pthread_mutex_t t_mtx;

typedef struct s_info
{
    int                 num_of_philos;
    size_t              time_to_die;
    size_t              time_to_eat;
    size_t              time_to_sleep;
    int                 num_times_to_eat;
    bool                is_dead;
    size_t              start_time;
    t_mtx               death_mtx;
    t_mtx               write_mtx;
    pthread_mutex_t     *forks;
}   t_info;

typedef struct s_philo
{
    pthread_t           thread;
    int                 id;
    int                 meal_count;
    size_t              last_meal_time;
    int                 status;
    t_mtx               *left_fork;
    t_mtx               *right_fork;
    t_info              *info;
}   t_philo;

#endif