#include "ft_printf.h"

void	ft_format_o(va_list ap, t_printf *all, int *pd, char c)
{
	unsigned long long int a;

	if (c == 'O')
		ft_modific(all, "l");
	a = va_arg(ap, unsigned long long int);
	if (all->l_m == 0)
		// a = va_arg(ap, unsigned int);
		a = (unsigned int)(a);
	else if (all->l_m == 1)
		// a = va_arg(ap, unsigned int) & 0xFFFF;
		a = (unsigned int)(a) & 0xFFFF;
	else if (all->l_m == 2)
		// a = va_arg(ap, unsigned short int) & 0xFF;
		a = (unsigned int)(a) & 0xFF;
	else if (all->l_m == 3)
		// a = va_arg(ap, unsigned long);
		a = (unsigned long)(a);
	else if (all->l_m == 4)
		// a = va_arg(ap, unsigned long long);
		a = (unsigned long long)(a);
	else if (all->l_m == 5)
		// a = va_arg(ap, uintmax_t);
		a = (uintmax_t)(a);
	else if (all->l_m == 6)
		// a = va_arg(ap, size_t);
		a = (size_t)(a);
	// (a == 0) ? ft_prnum(ft_strdup("0"), *all, c, pd) : 0;
	ft_prnum(ft_itoa_base(a, 8), *all, c, pd);
}
