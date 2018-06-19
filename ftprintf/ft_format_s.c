#include "ft_printf.h"

void	ft_putwchar(wchar_t chr, int *pd)
{
	if (chr <= 0x7F && (*pd)++)
		ft_putchar(chr);
	else if (chr <= 0x7FF && (*pd)++)
	{
		ft_putchar((chr >> 6) + 0xC0);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF && (*pd)++)
	{
		ft_putchar((chr >> 12) + 0xE0);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF && (*pd)++)
	{
		ft_putchar((chr >> 18) + 0xF0);
		ft_putchar(((chr >> 12) & 0x3F) + 0x80);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
}

void	ft_format_ss(va_list ap, t_printf *all, int *pd)
{
	wchar_t		*a;
	size_t		i;

	i = 0;
	a = va_arg(ap, wchar_t *);
	(void)all;
	while (*a)
		ft_putwchar(*a++, pd);
}
