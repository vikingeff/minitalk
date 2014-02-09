/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 12:34:16 by svermeer          #+#    #+#             */
/*   Updated: 2014/02/09 22:07:03 by gleger           ###   ########.fr       */
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
		usleep(10);
	}
	return (0);
}

int			check_pid(char *str)
{
	int		size;
	int		loop;

	loop = 0;
	size = ft_strlen(str);
	while (loop < size)
	{
		if (ft_isdigit(str[loop]))
		loop++;
	else
		return (EXIT_FAILURE);
	}
	return (0);
}

int			main(int ac, char **av)
{
	int		pid;
	int		index;

	index = 0;
	if (ac != 3)
		return (-1);
	if (check_pid(av[1]))
	{
		error(ERR_PID);
		return (EXIT_FAILURE);
	}
	else
	{
		pid = ft_atoi(av[1]);
		while (av[2][index])
		{
			if (send_info(av[2][index++], pid) == -1)
				return (-1);
		}
		if (send_info('\n', pid) == -1)
			return (-1);
	}
	return (0);
}
