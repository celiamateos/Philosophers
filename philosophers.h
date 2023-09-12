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
#include <errno.h>

typedef struct s_philo
{
    pthread_t thread;
    int     philo_num;
    int     meal_counter;
    
    struct s_data *data;
}               t_philo;

typedef struct s_data
{
    int philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int time_to_think;
    int meal_count;
}              t_data;

int main (int ac, char **av);
void    ft_error(int n);
# endif