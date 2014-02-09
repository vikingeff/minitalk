/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 20:10:33 by gleger            #+#    #+#             */
/*   Updated: 2014/02/09 22:11:32 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

int				ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int		clean_str(const char *str)
{
	int			index;

	index = 0;
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\n' 
		|| str[index] == '\r' || str[index] == '\f' || str[index] == '\v')
		index++;
	return (index);
}

int				ft_atoi(const char *str)
{
	int			index;
	int			res;
	int			sign;

	index		= clean_str(str);
	res		= 0;
	sign	= 1;
	if (*(str + index) == '-' || *(str + index) == '+')
		sign = (*(str + index++) == '-') ? -1 : 1;
	while (*(str + index) && *(str + index) >= '0' && *(str + index) <= '9')
	{
		res *= 10;
		res += (*(str + index) - '0');
		index++;
	}
	return (res * sign);
}
