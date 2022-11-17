#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nbr, int fd);
size_t	ft_strlen(char	*str);

int		print_int(int nbr);
int		print_str(char *str);
int		print_ptr(uintptr_t adr);
int		print_unsigned_int(unsigned int num);
int		print_hex_x(unsigned int num);
int		print_hex_X(unsigned int num);

int		print_converted(va_list *ap, const char *str);
int		ft_printf(const char *str, ...);

#endif
