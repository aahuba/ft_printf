#include "ft_printf.h"

char	*ft_format(va_list ap, t_printf *all, int *pd, char c)
{
	unsigned long long int a;

	if (c == 'O')
		ft_modific(all, "l");
	a = va_arg(ap, unsigned long long int);
	if (all->l_m == 0)
		a = (unsigned int)(a);
	else if (all->l_m == 1)
		a = (unsigned char)(a) & 0xFFFF;
	else if (all->l_m == 2)
		a = (unsigned short int)(a) & 0xFF;
	else if (all->l_m == 3)
		a = (unsigned long int)(a);
	else if (all->l_m == 5)
		a = (uintmax_t)(a);
	else if (all->l_m == 6)
		a = (size_t)(a);
	(c == 'O' || c == 'o') ? ft_prnum(ft_itoa_base(a, 8), *all, c, pd) : 0;
	(c == 'u') ? ft_prnum(ft_itoa_base(a, 10), *all, 'u', pd) : 0;
	if (c == 'x' || c == 'X')
		return (ft_itoa_base(a, 16));
	return (0);
}

void	ft_format_uu(va_list ap, t_printf *all, int *pd)
{
	unsigned long int a;

	ft_modific(all, "l");
	a = (unsigned long)va_arg(ap, long int);
	ft_prnum(ft_itoa_base(a, 10), *all, 'U', pd);
}

void	ft_format_xx(va_list ap, t_printf *all, int *pd, char c)
{
	char *a;

	a = ft_format(ap, all, pd, c);
	if (c == 'X')
		ft_strupper(a);
	ft_prnum(a, *all, c, pd);
}

void	ft_format_d(va_list ap, t_printf *all, int *pd)
{
	long long int	a;

	a = 0;
	if (all->l_m == 0)
		a = va_arg(ap, int);
	else if (all->l_m == 1)
		a = (signed char)va_arg(ap, int);
	else if (all->l_m == 2)
		a = (short)va_arg(ap, int);
	else if (all->l_m == 3)
		a = va_arg(ap, long);
	else if (all->l_m == 5)
		a = va_arg(ap, intmax_t);
	else if (all->l_m == 6)
		a = va_arg(ap, size_t);
	ft_prnum(ft_itoa(a), *all, 'd', pd);
}

void	ft_format_dd(va_list ap, t_printf *all, int *pd)
{
	long a;

	ft_modific(all, "l");
	a = va_arg(ap, long);
	ft_prnum(ft_itoa(a), *all, 'D', pd);
}
