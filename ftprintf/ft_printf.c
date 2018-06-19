#include "ft_printf.h"

void		ft_pstr(char *str, t_printf all, int *pd, char c)
{
	int		l;
	int		i;
	int		m;

	m = 0;
	if (!str)
	{
		m = 1;
		str = malloc(sizeof(char) * 7);
		str = ft_strcpy(str, "(null)");
	}
	l = (*str == '\0' && c == 'c') ? 1 : ft_strlen(str);
	if (l > all.prsn && (all.prsn != -1 && !(*str == '\0' && c == 'c')))
		l = all.prsn;
	i = (all.w > l && all.left != 1) ? (all.w - l) : 0;
	while (i > 0 && i-- && ++(*pd))
		(all.zero == 0) ? write(1, " ", 1) : write(1, "0", 1);
	(*str == '\0' && c == 'c' && ++(*pd)) ? write(1, "\0", 1) : 0;
	if (*str)
		while (i < l && ++(*pd))
			// write(1, &str[i++], 1);
			ft_putchar(str[i++]);
	i = (all.w > l && all.left == 1) ? (all.w - l) : 0;
	while (i--)
		(all.zero == 0 && ++(*pd)) ? write(1, " ", 1) : 0;
	(m == 1) ? free(str) : 0;
}

char		*ft_precision(t_printf *all, char *format)
{
	++format;
	all->prsn = ft_atoi(format);
	while (ft_isdigit((int)*format) && *format != '\0')
		format++;
	all->pres = 1;
	return (format);
}

void		parse_conv(t_printf *all, char *format)
{
	if (ft_strchr(TYPE, *format))
	{
		if (*format == 'i')
			*format = 'd';
		all->format[0] = *format;
	}
}

void	ft_char(t_printf all, va_list ap, int *pd)
{
	char	*s;
	
	s = malloc(sizeof(char) * 2);
	s[0] = va_arg(ap, int);
	s[1] = '\0';
	ft_pstr(s, all, pd, 'c');
	free(s);
}	

char	*ft_modific_2(t_printf *all, char *str)
{
	if (all->l_m < 3)
		all->l_m = 3;
	if (*(str + 1) != '\0' && *(str + 1) == 'l' && (*str++))
	{
		if (all->l_m < 4)
			all->l_m = 4;
	}
	return (str);
}

void	ft_modific_1(t_printf *all, char *str)
{
	if (*(str + 1) != '\0' && *(str + 1) == 'h')
	{
		if (all->l_m < 1)
			all->l_m = 1;
		str++;
	}
	else if (all->l_m < 2)
		all->l_m = 2;
}

void	ft_modific(t_printf *all, char *str)
{
	while (*str && (*str == 'h' || *str == 'l' || *str == 'z' || *str == 'j'))
	{
		if (*str == 'h')
			ft_modific_1(all, str);
		else if (*str == 'l')
			str = ft_modific_2(all, str);
		else if (*str == 'z')
			all->l_m = 6;
		else if (*str == 'j' && all->l_m != 6)
			all->l_m = 5;
		++str;
	}
}

// void	ft_chang_modif(int *n, t_printf all)
// {
// 	if (all.l_m == '0')
// 		*n = (int)(*n);
// 	if (all.l_m == '1')
// 		*n = (signed char)(*n);
// 	if (all.l_m == '2')
// 		*n = (short)(*n);
// 	if (all.l_m == '3')
// 		*n = (long)(*n);
// 	if (all.l_m == '5')
// 		*n = (intmax_t)(*n);
// 	if (all.l_m == '6')
// 		*n = (size_t)(*n);
// }

// void	ft_chang_modif_unsig(int *n, t_printf all)
// {
// 	if (all.l_m == '0')
// 		*n = (unsigned int)(*n);
// 	if (all.l_m == '1')
// 		*n = (unsigned char)(*n);
// 	if (all.l_m == '2')
// 		*n = (unsigned short int)(*n);
// 	if (all.l_m == '3')
// 		*n = (unsigned long int)(*n);
// 	if (all.l_m == '5')
// 		*n = (uintmax_t)(*n);
// 	if (all.l_m == '6')
// 		*n = (size_t)(*n);
// }

void	ft_prnum(char *s, t_printf all, char c, int *pd)
{
	// int		spaces;
	// int		l;

	// l = (s != NULL) ? (ft_strlen(s) : 0;
	// spaces = ft_spaces(all, s, l, c);
	// ft_prnum2(all, &spaces, pd, &l);
	(void)c;
	(void)all;
	// if (all.znak != 'n' && all.zero == 0 && ++(*pd))
	// 	write(1, &all.znak, 1);
	if ((*pd) += ft_strlen(s))
		ft_putstr(s);
}

// char		*ft_rev(char *start)
// {
// 	char	*new;
// 	char	*end;
// 	char	*new_start;

// 	end = start;
// 	new = ft_strnew(ft_strlen(start));
// 	new_start = new;
// 	while (*end)
// 		end++;
// 	end--;
// 	*new++ = *end;
// 	while (end - start != 0)
// 	*new++ = *(--end);
// 	free(start);
// 	return (new_start);
// }

// int			ft_base(char c)
// {
// 	int		base;

// 	base = (c == 'o') ? 8 : 16;
// 	if (c == 'i' || c == 'd' || c == 'D')
// 		base = (c == 'd') ? 10 : base;
// 	base = (c == 'u') ? 2 : base;
// 	return (base);
// }

// void		ft_i_b_u(char c, unsigned long long int n, t_printf all, int *pd)
// {
// 	long long int	i;
// 	char			*res;
// 	long long int	base;

// 	ft_chang_modif_unsig(&n, all);
// 	res = (char *)(malloc(sizeof(char) * 30));
// 	base = ft_base(&i, c);
// 	while (n > 0)
// 	{
// 		// if ((c == 'x' || c == 'X') && n % base > 9 && n % base < 17)
// 		// 	res[i++] = (c == 'x') ? 87 + n % base : 55 + n % base;
// 		// else
// 			// res[i++] = (char)(48 + n % base);
// 		res[i++] = (char)(48 + n % base);
// 		n = n / base;
// 	}
// 	res[i] = '\0';
// 	res = ft_rev(res);
// 	ft_prnum(res, all, c, pd);
// 	free(res);
// }

// static int		conv_ex(int nb)
// {
// 	if (nb >= 10)
// 		return (nb - 10 + 'a');
// 	else
// 		return (nb + '0');
// }

// void	ft_itoa_base(char c, int value, t_printf all, int *pd)
// {
// 	int					i;
// 	char				*str;
// 	int				tmp;
// 	int		base;
	
// 	if (c == 'i' || c == 'd' || c == 'D')
// 		ft_chang_modif(&value, all);
// 	else
// 		ft_chang_modif_unsig(&value, all);
// 	i = 0;
// 	tmp = value;
// 	base = ft_base(c);
// 	while (tmp >= base)
// 	{
// 		tmp = tmp / base;
// 		i++;
// 	}	
// 	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
// 		exit(1);
// 	str[i + 1] = '\0';
// 	while (i >= 0)
// 	{
// 		tmp = value % base;
// 		str[i] = conv_ex(tmp);
// 		value /= base;
// 		i--;
// 	}
// 	ft_prnum(str, all, c, pd);
// }

// void		ft_itoa_base(char c, long long int n, t_printf all, int *pd)
// {
// 	char			*res;
// 	long long int	i;
// 	long long int	base;

// 	if (c == 'i' || c == 'd' || c == 'D')
// 		ft_chang_modif(&n, all);
// 	else
// 		ft_chang_modif_unsig((unsigned long long int *)&n, all);
// 	i = 0;
// 	res = (char *)(malloc(sizeof(char) * 30));
// 	base = ft_base(&i, c);
// 	if (n < 0)
// 	{
// 		all.min = 1;
// 		n *= -1;
// 	}
// 	if (n == 0 && ++i)
// 		res[0] = '0';
// 	while (n > 0)
// 	{
// 		if ((c == 'x' || c == 'X') && n % base > 9 && n % base < 17)
// 			res[i++] = (c == 'x') ? 87 + n % base : 55 + n % base;
// 		else
// 			res[i++] = (char)(48 + n % base);
// 		// res[i++] = (char)(48 + n % base);
// 		n = n / base;
// 	}
// 	res[i] = '\0';
// 	res = ft_rev(res);
// 	if (c == 'i' || c == 'd' || c == 'D')
// 		ft_prnum(res, all, '\0', pd);
// 	else
// 		ft_prnum(res, all, c, pd);
// 	free(res);
// }

void		ft_numb(t_printf *all, va_list ap, int *pd)
{
	char	c;

	c = (all->format)[0];
	if (c == 'p')
	{
		// p = (unsigned long)va_arg(ap, void*);
		all->l_m = 4;
		all->point = 1;
		// ft_i_b_u('x', p, *all, pd);
		ft_format_p(ap, all, pd);
		// ft_itoa_base('x', p, *all, pd);
		// return ('0');
	}
	if (all->pres == 1) 
		all->zero = 0;
	// if (c == 'D' || c == 'U' || c == 'O')
	// 	ft_modific(all, "l");
	// *i = va_arg(ap, int);
	(c == 'i' || c == 'd') ? ft_format_d(ap, all, pd) : 0;
	(c == 'D') ? ft_format_dd(ap, all, pd) : 0;
	(c == 'x' || c == 'X') ? ft_format_xx(ap, all, pd, c) : 0;
	// if (c == 'i' || c == 'd' || c == 'D')
	// 	ft_itoa_base(c, *i, *all, pd);
	// if (c == 'x')
	// 	return ('x');
		// ft_i_b_u('x', i, *all, pd);
	// if (c == 'X')
	// 	return ('X');
		// ft_i_b_u('X', i, *all, pd);
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U')
	{
			// return ('o');
			// ft_i_b_u('o', i, *all, pd);
		if (c == 'u')
			ft_format(ap, all, pd, c);
		else if (c == 'U')
			ft_format_uu(ap, all, pd);
		else
			ft_format(ap, all, pd, c);
			// return ('d');
			// ft_i_b_u('d', i, *all, pd);
	}
	// return ('0');
}

void		ft_chr(t_printf *all, va_list ap, int *pd)
{
	if ((all->format)[0] == 's' && all->l_m != 3)
		ft_pstr(va_arg(ap, char *), *all, pd, 's');
	// else if ((all->format)[0] == 'S' || (c == 's' && opt->modif == 3))
	// 	ft_unicode_s(ap, all, pd);
	else if ((all->format)[0] == 'c' && all->l_m != 3)
		ft_char(*all, ap, pd);
	// else if ((all->format)[0] == 'C' || (c == 'c' && opt->modif == 3))
	// 	ft_unicode_c(ap, all, pd);
}

void		ft_type(t_printf *all, va_list ap, char format, int *pd)
{
	parse_conv(all, &format);
	ft_modific(all, all->format_spec);
	if ((all->format)[0] == 's' || (all->format)[0] == 'S' || \
		(all->format)[0] == 'c' || (all->format)[0] == 'C')
		ft_chr(all, ap, pd);
	else if ((all->format)[0] == '%')
		ft_format_percent(all, pd);
	// else if ((all->format)[0] == 'p')
	// {
	// 	p = (unsigned long)va_arg(ap, void*);
	// 	all->l_m = 4;
	// 	all->point = 1;
	// 	ft_i_b_u('x', p, *all, pd);
	// }
	else
		ft_numb(all, ap, pd);
	// if (c != '0')
	// 	// ft_i_b_u(c, i, *all, pd);
	// 	ft_itoa_base(c, i, *all, pd);
}

void	ft_flag(t_printf *all, char c)
{
	if (c == '+')
		all->znak = '+';
	else if (c == ' ' && all->znak != '+')
		all->znak = ' ';
	else if (c == '-')
	{
		all->zero = 0;
		all->left = 1;
	}
	else if (c == '0' && all->left != 1)
		all->zero = 1;
	else if (c == '#')
		all->hash = 1;
}

t_printf	*init_printf(t_printf *all)
{
	if ((all = (t_printf *)malloc(sizeof(t_printf))) == NULL)
		exit(1);
	// all->flag = 'e';
	all->zero = 0;
	all->w = 0;
	all->prsn = -1;
	all->pres = 0;
	all->spec = 0;
	all->minus = 0;
	all->hash = 0;
	all->left = 0;
	all->l_m = 0;
	all->point = 0;
	all->min = 0;
	all->znak = 'n';
	// all->tochn_bool = 'e';
	all->format = ft_strnew(1);
	all->format_spec = ft_strnew(2);
	return (all);
}

char	is_changeable(char *c)
{
	if (*c == '.' && *(c + 1) && (*(c + 1) >= '0' && *(c + 1) <= '9'))
		return ('p');
	if (*c == '.' && *(c + 1) && !(*(c + 1) >= '0' && *(c + 1) <= '9'))
		return ('g');
	if (ft_strchr(FLAG, *c))
		return ('f');
	if (*c >= '1' && *c <= '9')
		return ('w');
	if (ft_strchr(SPEC, *c))
		return ('m');
	if (ft_strchr(TYPE, *c))
		return ('t');
	return ('0');
}

char	*ft_check(t_printf *all, char *format, int *pd, va_list ap)
{
	int		i;

	i = 0;
	all = init_printf(all);
	while (*format != '\0')
	{
		if (is_changeable(format) == '0')
			return (format);
		else if (is_changeable(format) == 'f')
			ft_flag(all, (*format++));
		else if (is_changeable(format) == 'w')
		{
			all->w = ft_atoi(format);
			while (ft_isdigit(*format))
				format++;
			continue;
		}
		else if (is_changeable(format) == 'm')
		{
			while (*format && ft_strchr(SPEC, *format))
			{
				(all->format_spec)[i++] = *format;
				format++;
			}
		}
		else if (is_changeable(format) == 'p')
			format = ft_precision(all, format);
		else if (is_changeable(format) == 't')
		{
			ft_type(all, ap, *format, pd);
			return (++format);
		}
		else if (format++)
			ft_precision(all, "0");
	}
	return (NULL);
}

int     ft_printf(char *format, ...)
{
	va_list		ap;
	int			pd;
	char		*ptr;
	t_printf    *all;

	if (ft_strcmp(format, "%") == 0)
		return (0);
	all = NULL;
	pd = 0;
	va_start(ap, format);
	while (format && *format)
	{
		while (*format != '\0' && *format != '%' && ++pd)
			ft_putchar(*format++);
		if (*format != '\0' && *format++ == '%')
		{
			ptr = ft_check(all, format, &pd, ap);
			format = ptr;
		}
	}
	va_end(ap);
	return (pd);
}