#include "ft_printf.h"

void	ft_format_percent(t_printf *all, int *pd)
{
	if (all->pres == 0)
			all->pres = 1;
	ft_pstr(ft_strdup("%"), *all, pd, 's');
}
