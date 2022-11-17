/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:16:59 by kazuki            #+#    #+#             */
/*   Updated: 2022/11/18 07:37:41 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

size_t	count_digits(int num)
{
	size_t	digits;

	if (num == INT_MIN)
		return (11);
	digits = 0;
	if (num < 0)
	{
		num *= -1;
		digits++;
	}
	while (num > 10)
	{
		num /= 10;
		digits++;
	}
	digits++;
	return (digits);
}

int	print_int(int nbr)
{
	size_t			digits;
	long long int	n;

	n = nbr;
	digits = count_digits(nbr);
	ft_putnbr_fd(n, 1);
	return (digits);
}

int	print_str(char *str)
{
	size_t	len;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	return (len);
}

int	print_ptr(uintptr_t adr)
{
	int	res;

	res = 0;
	if (adr / 16)
		res = print_ptr(adr / 16);
	if (adr % 16 >= 10)
	{
		ft_putchar_fd(adr % 16 - 10 + 'a', 1);
		res++;
	}
	else
	{
		ft_putchar_fd(adr % 16 + '0', 1);
		res++;
	}
	return (res);
}

int	print_unsigned_int(unsigned int num)
{
	int	res;

	res = 0;
	if (num / 10)
		res += print_unsigned_int(num / 10);
	ft_putchar_fd(num % 10 + '0', 1);
	res++;
	return (res);
}

int	print_hex_x(unsigned int num)
{
	int	res;

	res = 0;
	if (num / 16)
		res += print_hex_x(num / 16);
	if (num % 16 >= 10)
	{
		ft_putchar_fd(num % 16 - 10 + 'a', 1);
		res++;
	}
	else
	{
		ft_putchar_fd(num % 16 + '0', 1);
		res++;
	}
	return (res);
}

int	print_hex_X(unsigned int num)
{
	int	res;

	res = 0;
	if (num / 16)
		res += print_hex_X(num / 16);
	if (num % 16 >= 10)
	{
		ft_putchar_fd(num % 16 - 10 + 'A', 1);
		res++;
	}
	else
	{
		ft_putchar_fd(num % 16 + '0', 1);
		res++;
	}
	return (res);
}

int	print_converted(va_list *ap, const char *str)
{
	int	ret;

	ret = 0;
	if (*str == 'd' || *str == 'i')
		ret += print_int(va_arg(*ap, int));
	else if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		ret++;
	}
	else if (*str == 'c')
	{
		ft_putchar_fd(va_arg(*ap, int), 1);
		ret++;
	}
	else if (*str == 'p')
	{
		ft_putstr_fd("0x", 1);
		ret += 2;
		ret += print_ptr(va_arg(*ap, uintptr_t));
	}
	else if (*str == 's')
		ret += print_str(va_arg(*ap, char *));
	else if (*str == 'u')
		ret += print_unsigned_int(va_arg(*ap, unsigned int));
	else if (*str == 'x')
		ret += print_hex_x(va_arg(*ap, unsigned int));
	else if (*str == 'X')
		ret += print_hex_X(va_arg(*ap, unsigned int));
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			ret++;
		}
		else
		{
			str++;
			ret += print_converted(&ap, str);
		}
		str++;
	}
	va_end(ap);
	return (ret);
}

/*int	main(void)
{
	int		res;
	int		res2;

	res = ft_printf("hoge\n");
	res2 = printf("hoge\n");
	printf("%d\n", res);
	res = ft_printf("%d\n", 120);
	res2 = printf("%d\n", 120);
	if (res == res2)
		puts("ok");
	res = ft_printf("%d\n", 0);
	res2 = printf("%d\n", 0);
	if (res == res2)
		puts("ok");
	res = ft_printf("%d\n", -0);
	res2 = printf("%d\n", -0);
	if (res == res2)
		puts("ok");
	res = ft_printf("%d\n", INT_MAX);
	res2 = printf("%d\n", INT_MAX);
	if (res == res2)
		puts("ok");
	res = ft_printf("%d\n", INT_MIN);
	res2 = printf("%d\n", INT_MIN);
	if (res == res2)
		puts("ok");
	res = ft_printf("%s\n", "hoge");
	res2 = printf("%s\n", "hoge");
	if (res == res2)
		puts("ok");
	char *hoge = "aiueo";
	res = ft_printf("%s\n", hoge);
	res2 = printf("%s\n", hoge);
	if (res == res2)
		puts("ok");
	res = ft_printf("%s\n", "");
	res2 = printf("%s\n", "");
	if (res == res2)
		puts("ok");
	res = ft_printf("%c\n", 'Q');
	res2 = printf("%c\n", 'Q');
	if (res == res2)
		puts("ok");	
	res = ft_printf("%p\n", hoge);
	res2 = printf("%p\n", hoge);
	printf("ft_printf = %d, original = %d\n", res, res2);
	if (res == res2)
		puts("ok");
	hoge = NULL;
	res = ft_printf("%p\n", hoge);
	res2 = printf("%p\n", hoge);
	printf("ft_printf = %d, original = %d\n", res, res2);
	if (res == res2)
		puts("ok");	
	res = ft_printf("%u\n", UINT_MAX);
	res2 = printf("%u\n", UINT_MAX);
	if (res == res2)
		puts("ok");
	res = ft_printf("%x\n", 123);
	res2 = printf("%x\n", 123);
	if (res == res2)
		puts("ok");
	res = ft_printf("%%\n");
	res2 = printf("%%\n");
	if (res == res2)
		puts("ok");
	res = ft_printf("%X\n", 123);
	res2 = printf("%X\n", 123);
	if (res == res2)
		puts("ok");
	printf("%s\n", hoge);
	res = ft_printf("%s, %s\n","hoge", hoge);
	res2 = printf("%s, %s\n", "hoge", hoge);
	if (res == res2)
		puts("ok");
}
*/
