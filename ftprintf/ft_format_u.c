#include "ft_printf.h"

void	ft_format_u(va_list ap, t_printf *all, int *pd)
{
	unsigned long long int a;

	a = 0;
	if (all->l_m == 1)
		a = va_arg(ap, unsigned int) & 0xFFFF;
	else if (all->l_m == 2)
		a = va_arg(ap, unsigned int) & 0xFF;
	else if (all->l_m == 3)
		a = va_arg(ap, unsigned long);
	else if (all->l_m == 4)
		a = va_arg(ap, unsigned long long);
	else if (all->l_m == 5)
		a = va_arg(ap, uintmax_t);
	else if (all->l_m == 6)
		a = va_arg(ap, size_t);
	else if (all->l_m == 0)
		a = va_arg(ap, unsigned int);
	ft_prnum(ft_itoa_base(a, 10), *all, 'u', pd);
}

void	ft_format_uu(va_list ap, t_printf *all, int *pd)
{
	unsigned long int a;

	ft_modific(all, "l");
	a = (unsigned long)va_arg(ap, long int);
	ft_prnum(ft_itoa_base(a, 10), *all, 'U', pd);
}
