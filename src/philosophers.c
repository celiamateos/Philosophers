/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:55:01 by cmateos-          #+#    #+#             */
/*   Updated: 2023/10/01 15:55:03 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./../philosophers.h"

void    leaks()
{
	system ("leaks -q philosophers");
}

int	ft_start_pthreads(t_data *data, t_philo *philo)
{
	int size;
	int i;

	i = 0;
	size = data->nbr_philos;
	while (i < size)
	{
		if (pthread_create(&philo[i].id, NULL, ft_routine, (void *)&philo[i]))
		{
			printf("\nError al crear el hilo");
			ft_clean(data, philo);
		}

		i++;
	}
	return (0);
}

int	ft_join_pthreads(t_philo *philo, t_data *data)
{
	int size;
	int	i;

	i = 0;
	size = data->nbr_philos;
	while (i < size)
	{
		if (pthread_join((philo[i].id), NULL) != 0)
		{
			printf("\nError,");
			ft_clean(data, philo);
		}
		i++;
	}

	return (0);
}

int main (int ac, char **av)
{
	// atexit(leaks);
	t_data *data;
	t_philo *philo = 0;

	data = (t_data *)malloc(1 * sizeof(t_data));
	if (!data)
		return (-1);
	if (ft_check_args(ac, av))
	{
		printf("Error\n Bad arguments!");
		free(data);
	}
	philo = ft_init(ac, av, data);
	if (philo == NULL)
		return (1);
	if (ft_start_pthreads(data, philo))
		ft_clean(data, philo);
	if (ft_join_pthreads(philo, data))
		ft_clean(data, philo);
	printf("\nNúmero de philoss:%d", data->nbr_philos);
	printf("\nTime to die:%ld", data->time_to_die);
	printf("\nTime to eat:%ld", data->time_to_eat);
	printf("\nTime to sleep:%ld", data->time_to_sleep);
	ft_clean(data, philo);
	exit (1);
	return (0);
}

