#include "ft_printf.h"

char	*ft_format_x(va_list ap, t_printf *all)
{
	unsigned long long int a;

	a = va_arg(ap, unsigned long long int);
	if (all->l_m == 1)
		a = va_arg(ap, unsigned int) & 0xFFFF;
	else if (all->l_m == 2)
		// a = va_arg(ap, unsigned short) & 0xFF;
		a = (unsigned char)(a) & 0xFF;
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
	return(ft_itoa_base(a, 16));
}

void	ft_format_xx(va_list ap, t_printf *all, int *pd, char c)
{
	char *a;

	a = ft_format_x(ap, all);
	if (c == 'X')
		ft_strupper(a);
	// return (a);
	ft_prnum(a, *all, c, pd);
}
