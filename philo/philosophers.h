/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:31:28 by cmateos           #+#    #+#             */
/*   Updated: 2023/10/06 19:31:31 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define FORK "\x1b[1;33mhas taken a fork\x1b[0m"
# define EAT "\x1b[1;32mis eating\x1b[0m"
# define SLEEP "\x1b[1;34mis sleeping\x1b[0m"
# define THINK "\x1b[1;35mis thinking\x1b[0m"
# define DIED "died\x1b[0m"

typedef struct s_data
{
	int				i;
	char			**args;
	int				nbr_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meal_count;
	int				philo_died;
	char			*shared_fork;
	long			tv_sec;
	int				tv_usec;
	pthread_mutex_t	*m_philo_died;
	pthread_mutex_t	**m_fork;
	pthread_mutex_t	*m_write;

}					t_data;

typedef struct s_philo
{
	t_data		*data;
	pthread_t	id;
	int			philo_index;
	long		death_time;
	long		first_time;
	int			forks;
	long		time_last_meal;
	int			lock;
}				t_philo;

//INIT
int		main(int ac, char **av);
int		ft_check_args(t_data *data, int ac, char **av);
t_philo	*ft_init(int ac, char **av, t_data *data);

//ROUTINE
void	*ft_routine(void *philos);
int		is_sleeping(t_philo *philo);
int		is_eating(t_philo *philo);
int		ft_print_status(t_philo *philo, char *msg);

//CHECK DIE
int		check_die(t_philo *philo);
int		check_any_die(t_philo *philo);
int		check_i_die(t_philo *philo);

//TIME
int		ft_waiting_to_live(t_philo *philo, long time);
long	get_time(t_data *data);
void	ft_mssleep(long ms, t_data *data);

//UTILS
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_free_array(char **arr);
int		len_array(char **av);
long	ft_atol(const char *str);

//FREE AND CLEAN
void	ft_clean(t_data *data, t_philo *philo);
void	ft_error(t_data *data, t_philo *philo, char *str);
void	ft_free(t_data *data, t_philo *philo);

#endif
