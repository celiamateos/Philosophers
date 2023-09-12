/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:06:56 by cmateos-          #+#    #+#             */
/*   Updated: 2023/09/01 17:06:58 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./../philosophers.h"

int   ft_check_av(char **av, t_data *data)
{
    int i = 0;
    int j;
    while (av[++i])
    {
        j = -1;
        while (av[i][++j])
        {
            if (!ft_isdigit(av[i][j]))
                return (-1);
        }
    }
    data->philos = atoi(av[1]);
    data->time_to_die = atoi(av[2]);
    data->time_to_eat = atoi(av[3]);
    data->time_to_sleep = atoi(av[4]);
    if (av[5])
        data->meal_count = atoi(av[5]);
    if (data->philos < 1 || data->philos > 200 
    || data->time_to_die < 0 || data->meal_count < 0)
        return (-1);
    return (0);
}



int main (int ac, char **av)
{
    t_data data;

    if (ac == 5 || ac == 6)
    {
        if (ft_check_av(av, &data) == -1)
            return (1);
        ft_init(&data);

    }

    return 0;

}
