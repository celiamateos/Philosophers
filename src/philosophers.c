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
#include "/../philosophers.h"

void    ft_check_av(char *av1, char* av2, char *av3, char *av4)
{
    int n;

    n = atoi(av1);
    if (av1 < 2)
        ft_error(0);
}

int main (int ac, char **av)
{
    if (ac == 5)
        ft_check_av(av[1], av[2], av[3], av[4]);
    return 0;

}
