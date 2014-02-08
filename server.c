/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svermeer <svermeer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 12:35:18 by svermeer          #+#    #+#             */
/*   Updated: 2014/02/08 12:49:17 by svermeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include				<sys/types.h>
#include				<signal.h>
#include				<sys/wait.h>
#include				<minitalk.h>

void					receive_signal(int signal, siginfo_t *siginfo, void *unused)
{
	static char			value = 64;
	static char			bit = 0;

	(void)unused;
	(void)siginfo;
	if (signal == SIGUSR2)
		bit = bit + value;
	value = value / 2;
	if (value == 0)
	{
		ft_putchar(bit);
		value = 64;
		bit = 0;
	}
}

void    show_usage(char *prog_name)
{
  error("Usage: ");
  error(prog_name);
  error("\n");
}

int					main(int argc, char **argv)
{
	int					pid;
	struct sigaction	catch;

  if (argc == 1)
  {
	  if ((pid = getpid()) == -1)
		  return (error("Error on getpid\n"));
	  ft_putstr("Le PID du serveur est : ");
    ft_putnbr(pid);
	  ft_putchar('\n');
	  catch.sa_flags = SA_SIGINFO;
	  catch.sa_sigaction = receive_signal;
	  if ((sigaction(SIGUSR1, &catch, 0)) == -1)
		  return (error("Error on sigaction\n"));
	  if ((sigaction(SIGUSR2, &catch, 0)) == -1)
		  return (error("Error on sigaction\n"));
	  while (42)
		  pause();
  }
  else
  {
    show_usage(argv[0]);
    return (EXIT_FAILURE);
  }
	return (EXIT_SUCCESS);
}
