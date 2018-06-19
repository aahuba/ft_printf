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
