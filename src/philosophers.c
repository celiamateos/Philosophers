/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers->c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student->42madrid->com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:06:56 by cmateos-          #+#    #+#             */
/*   Updated: 2023/09/01 17:06:58 by cmateos-         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./../philosophers.h"

void    leaks()
{
	system ("leaks -q philosophers");
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	philo->time_last_meal = get_time();
	printf("\nphilo %d has taken a fork", philo->philo_index);
	printf("\nphilo %d has taken a fork", philo->philo_index);
	pthread_mutex_lock(&philo->data->m_write);
	printf("\nphilo %d is eating", philo->philo_index);
	pthread_mutex_unlock(&philo->data->m_write);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}


void	*ft_routine(void *philos)
{
	t_philo *philo;
	int *ret = 0;
	int limit;

	philo = (t_philo *)philos;
	printf("\nEmpieza la rutina!");
	limit = 3;
	while (limit > 0)
	{
		// printf("\n%dey,", philo->philo_index);
		// printf("philo id:%ld", philo->philo_id);
		is_eating(philo);
		limit--;
	}

	return((void *)ret);
}

int	ft_start_pthreads(t_data *data, t_philo *philo)
{
	int size;
	int i;

	i = 0;
	size = data->nbr_philos;
	while (i < size)
	{
		if (pthread_create(&philo[i].philo_id, NULL, ft_routine, (void *)&philo[i]))
		{
			printf("\nError al crear el hilo");
			return (-1);
		}

		i++;
	}
	return (0);
}

void ft_join_pthreads(t_philo *philo, t_data *data)
{
	int size;
	int	i;
	void *status;

	i = 0;
	size = data->nbr_philos;
	while (i < size)
	{
		pthread_join((philo[i].philo_id), &status);
		i++;
	}
	free(status);
	// return (0);
}

void ft_clean(t_data *data)
{
	int i = 0;
	while (i < data->nbr_philos)
        {
                pthread_mutex_destroy(&data->m_fork[i]);
	        	pthread_mutex_destroy(data->philo[i].l_fork);
                pthread_mutex_destroy(data->philo[i].r_fork);
                i++;
        }
        pthread_mutex_destroy(&data->m_write);
}

int main (int ac, char **av)
{
	// atexit(leaks);
	t_data *data;
	t_philo *philo;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (-1);
	if (ft_check_args(ac, av))
	{
		printf("Error\n Bad arguments!");
		ft_free(data, NULL);
	}
	philo = ft_calloc(data->nbr_philos, sizeof(t_philo));
	if (!philo)
		return (-1);
	ft_init(ac, av, data, philo);
	if (ft_start_pthreads(data, philo))
		ft_free(data, philo);
	ft_join_pthreads(philo, data);
		// ft_free(data, philo);
	printf("\nNúmero de philoss:%d", data->nbr_philos);
	printf("\nTime to die:%d", data->time_to_die);
	printf("\nTime to eat:%d", data->time_to_eat);
	printf("\nTime to sleep:%d", data->time_to_sleep);
	ft_clean(data);
	ft_free(data, philo);
	return (0);
}