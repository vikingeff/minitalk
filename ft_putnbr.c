/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svermeer <svermeer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:21:34 by svermeer          #+#    #+#             */
/*   Updated: 2014/02/08 12:25:42 by svermeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

void		ft_putnbr(int nb)
{
    if (nb < 0)
	{
		ft_putchar('-');
		if (nb <= -10)
			ft_putnbr(nb / -10);
		ft_putchar(nb % 10 * (-1) + '0');
	}
    else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}
