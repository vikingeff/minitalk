/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svermeer <svermeer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 10:56:45 by svermeer          #+#    #+#             */
/*   Updated: 2014/02/08 13:01:18 by svermeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef			MINITALK_H_
# define		MINITALK_H_

# include <unistd.h>
# include <stdlib.h>

# define ERR_PID "Le PID n'est pas conforme.\n"

typedef struct	s_sig
{
	int			size;
	int			pid;
	char		c;
}				t_sig;

int				ft_strlen(char *str);
int				error(char *str);
int 			ft_putchar(char c);
void			ft_putnbr(int nb);
int       ft_putstr(char *str);
int       ft_isdigit(int c);

#endif			/* !MINITALK_H_ */
