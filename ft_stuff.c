#include <minitalk.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
  return (1);
}

int    ft_putstr(char *str)
{
  write(1, str, ft_strlen(str));
  return (ft_strlen(str));
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int			error(char *str)
{
	write(2, str, ft_strlen(str));
	return (-1);
}

void		ft_putnbr(int nb)
{
  if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}
