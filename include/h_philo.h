#ifndef H_PHILO_H
 # define H_PHILO_H
 # define   THINK   0b00000001
 # define   EAT     0b00000010
 # define   SLEEP   0b00000100
 # include <stdio.h>
 # include <stdlib.h>
 # include <pthread.h>
 # include <stdbool.h>
 # include <errno.h>
 # include <unistd.h>
 # include <sys/time.h>

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

//monitor
void    *monitor(void   *args);

// prepare
int init_program(t_info	*info, t_philo	*philos[], t_mtx	**forks, 
	char	*argv[]);
void	input_data(t_info *info, char **argv);
void	set_philos(t_philo	*philo, t_info	*info, t_mtx	*forks);

//move
void	think(t_philo *philo);
void	sleeping(t_philo *philo);
void	eat(t_philo *philo);

//thread
int	    create_thread(t_info   *info, t_philo *philos);

//check
int check_input(char *argv[]);

//clear
void clean_all(t_info *info, t_philo *philos, t_mtx  *forks);

//utils
size_t	get_current_time(void);
int	    ft_usleep(size_t msec);

//libft
int					ft_isdigit(int c);
int	                ft_atoi(const char *str);
#endif