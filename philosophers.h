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
# include <errno.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				nbr_philos;
	int 			time_to_die;
	int 			time_to_eat;
	int 			time_to_sleep;
	int 			meal_count;
	int				philo_died;
	pthread_mutex_t	*m_fork;
	pthread_mutex_t m_write;
}              t_data;

typedef struct s_philo
{
	t_data	*data;
	pthread_t		*philo_id;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	int     philo_index;
	int		death_time;
	int     meal_counter;
	long long	time_last_meal;
	
}               t_philo;

int		main (int ac, char **av);
int ft_check_args(int ac, char **av);
int		ft_init(int ac, char **av, t_data *data, t_philo *philo);
long	get_time(void);

//UTILS

int		ft_error(int n, t_data *data, t_philo *philo);
int		ft_free(t_data *data, t_philo *philo);
void	*ft_calloc(size_t count, size_t size);
char    **ft_split(char const *s, char c);
char    *ft_substr(char const *s, unsigned int start, size_t len);
void    ft_free_array(char **arr);
int		len_array(char **av);
long     ft_atol(const char *str);
# endif
