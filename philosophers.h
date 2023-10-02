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
	long		time_to_die;
	long 		time_to_eat;
	long			time_to_sleep;
	int 			meal_count;
	int				philo_died;
	pthread_mutex_t	*m_philo_died;
	pthread_mutex_t	*m_fork;
	pthread_mutex_t m_write;

}              t_data;

typedef struct s_philo
{
	t_data	*data;
	pthread_t		id;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	int     philo_index;
	long	death_time;
	long 	first_time;
	int     meal_counter;
	long	time_last_meal;
	
}           t_philo;

int		main (int ac, char **av);
int 	ft_check_args(int ac, char **av);
t_philo	*ft_init(int ac, char **av, t_data *data);
long	get_time(void);

//ROUTINE
void	*ft_routine(void *philos);
int	is_sleeping(t_philo *philo);
int	is_eating(t_philo *philo);

//UTILS
long	get_time(void);
int   ft_print_status(t_philo *philo, char *msg);
void	*ft_calloc(size_t count, size_t size);
char    **ft_split(char const *s, char c);
char    *ft_substr(char const *s, unsigned int start, size_t len);
void    ft_free_array(char **arr);
int		len_array(char **av);
long     ft_atol(const char *str);

//FREE AND CLEAN
void	ft_clean(t_data *data, t_philo *philo);
int		ft_error(int n, t_data *data, t_philo *philo);
void		ft_free(t_data *data, t_philo *philo);

# endif
