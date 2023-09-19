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

int ft_free(t_data *data, t_philo *philo)
{
	if(philo)
		free(philo);
	if(data->tpid)
		free(data->tpid);
	if(data->fork)
		free(data->fork);
	if(data)
		free(data);
	exit (1);
	return 0;
}

int main (int ac, char **av)
{
	//atexit(leaks);
	t_data *data;
	t_philo *philo;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (0);
	if (ac == 5 || ac == 6)
	{
		if (ft_check_av(av, data))
			return (ft_error(0, data, NULL));
		philo = ft_calloc(data->nbr_philos, sizeof(t_philo));
			if (!philo)
		return (ft_error(0, data, philo));
		ft_init(data, philo);
	}
	printf("\nNúmero de philos:%d", data->nbr_philos);
	printf("\nTime to die:%d", data->time_to_die);
	printf("\nTime to eat:%d", data->time_to_eat);
	printf("\nTime to sleep:%d", data->time_to_sleep);
	ft_free(data, philo);
	return 0;

}