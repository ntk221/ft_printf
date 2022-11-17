#include "./includes/ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(1, &c, 1));
}

int	ft_putstr_fd(char *str, int fd)
{
	int	len;

	if (!str)
		return (-1);
	len = 0;
	while (*str)
		len++;
	return (write(1, str, len));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n < 10)
			ft_putchar_fd(n + '0', fd);
		else
		{
			ft_putnbr_fd((n / 10), fd);
			ft_putnbr_fd((n % 10), fd);
		}
	}
}

size_t	ft_strlen(char	*str)
{
	size_t	len;

	len = 0;
	while(*str)
	{
		len++;
		str++;
	}
	return (len);
}