#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>
# include <sys/wait.h>
# include "./libft/libft.h"
# include <errno.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_t	*tpid;
	int nbr_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int time_to_think;
	int meal_count;
	long	start_time;
	pthread_mutex_t *fork;
}              t_data;

typedef struct s_philo
{
	t_data	*data;
	pthread_t thread;
	int     philo_num;
	int     meal_counter;
	
}               t_philo;


int		main (int ac, char **av);
int   	ft_check_av(char **av, t_data *data);
int		ft_error(int n, t_data *data, t_philo *philo);
int		ft_init(t_data *data, t_philo *philo);
long		get_time(void);
int		ft_free(t_data *data, t_philo *philo);
# endif
