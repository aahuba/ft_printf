#include "ft_printf.h"

void	ft_format_d(va_list ap, t_printf *all, int *pd)
{
	long long int	a;

	a = 0;
	if (all->l_m == 1)
		a = (short int)va_arg(ap, int);
	else if (all->l_m == 2)
		a = (char)va_arg(ap, int);
	else if (all->l_m == 3)
		a = va_arg(ap, long);
	else if (all->l_m == 4)
		a = va_arg(ap, long long);
	else if (all->l_m == 5)
		a = va_arg(ap, intmax_t);
	else if (all->l_m == 6)
		a = va_arg(ap, long long int);
	else if (all->l_m == 0)
		a = va_arg(ap, int);
	ft_prnum(ft_itoa(a), *all, 'd', pd);
}

void	ft_format_dd(va_list ap, t_printf *all, int *pd)
{
	long a;

	ft_modific(all, "l");
	a = va_arg(ap, long);
	ft_prnum(ft_itoa(a), *all, 'D', pd);
}
