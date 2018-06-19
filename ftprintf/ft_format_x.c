#include "ft_printf.h"

// char	*ft_format_x(va_list ap, t_printf *all)
// {
// 	unsigned long long int a;

// 	a = va_arg(ap, unsigned long long int);
// 	if (all->l_m == 0)
// 		// a = va_arg(ap, unsigned int);
// 		a = (unsigned int)(a);
// 	else if (all->l_m == 1)
// 		// a = va_arg(ap, unsigned int) & 0xFFFF;
// 		a = (unsigned char)(a) & 0xFFFF;
// 	else if (all->l_m == 2)
// 		// a = va_arg(ap, unsigned short int) & 0xFF;
// 		a = (unsigned short int)(a) & 0xFF;
// 	else if (all->l_m == 3)
// 		// a = va_arg(ap, unsigned long);
// 		a = (unsigned long int)(a);
// 	else if (all->l_m == 5)
// 		// a = va_arg(ap, uintmax_t);
// 		a = (uintmax_t)(a);
// 	else if (all->l_m == 6)
// 		// a = va_arg(ap, size_t);
// 		a = (size_t)(a);
// 	return(ft_itoa_base(a, 16));
// }

void	ft_format_xx(va_list ap, t_printf *all, int *pd, char c)
{
	char *a;

	a = ft_format(ap, all, pd, c);
	if (c == 'X')
		ft_strupper(a);
	// return (a);
	ft_prnum(a, *all, c, pd);
}
