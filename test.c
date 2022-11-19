#include "./includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		res;
	int		res2;

	// ft_putchar_fd('a', 1);

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
	exit(1);
}
