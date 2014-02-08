/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svermeer <svermeer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 12:34:16 by svermeer          #+#    #+#             */
/*   Updated: 2014/02/08 14:52:44 by svermeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<signal.h>
#include	<string.h>
#include	<minitalk.h>

int			send_info(char c, int pid)
{
	int		nb;

	nb = 64;
	while (nb != 0)
	{
		if (c >= nb)
		{
			c = c - nb;
			if (kill(pid, SIGUSR2) == -1)
				return (error("Error on kill\n"));
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				return (error("Error on kill\n"));
		}
		nb = nb / 2;
		usleep(1000);
	}
	return (0);
}

int			main(int ac, char **av)
{
	int		pid;
	int		j;

	j = 0;
	if (ac != 3)
		return (-1);
	pid = atoi(av[1]);
	while (av[2][j])
	{
		if (send_info(av[2][j++], pid) == -1)
			return (-1);
	}
	return (0);
}
