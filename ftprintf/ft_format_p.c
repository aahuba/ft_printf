#include "ft_printf.h"

void	ft_format_p(va_list ap, t_printf *all, int *pd)
{
	char *a;
	char *ret;

	a = va_arg(ap, char*);
	all->h = 1;
	ret = ft_strdup("0x");
	ft_strcat(ret, ft_itoa_base((unsigned long int)a, 16));
	ft_prnum(ret, *all, 'p', pd);
}
