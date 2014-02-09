/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 10:56:45 by svermeer          #+#    #+#             */
/*   Updated: 2014/02/09 22:25:35 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>

# define ERR_PID "Le PID n'est pas conforme.\n"

typedef struct	s_sig
{
	int			size;
	int			pid;
	char		c;
}				t_sig;

int				ft_strlen(char *str);
int				error(char *str);
int				ft_putchar(char c);
void			ft_putnbr(int nb);
int				ft_putstr(char *str);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);

#endif /* !MINITALK_H */
