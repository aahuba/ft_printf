
#include <ft_printf.h>

/* 
specificator '%', code of format everyrhing after '%':
	while ( != "\0" || != '%')

Если количество аргументов меньше, чем количество команд форматирования, то вывод не­определен. 
Если же количество аргументов больше, чем команд форматирования, то лишние ар­гументы отбрасываются.

int between % and letter of formatting - minimum width of field
puts '0' || ' ' to fill field of output
if number or string is bigger than this int - prints all
Например, %05d будет дополнять числа, состоящие из менее чем 5 цифр, нулями до пяти цифр. 

modificator of accuracy - .4
prints number with 4 symbols after '.'
%10.4f озна­чает вывод числа шириной минимум 10 символов с четырьмя знаками после точки.
Однако при использовании совместно со спецификаторами g или G модификатор точности задает максималь­ное количество отображаемых значащих цифр.
if number - it shows minimum number of symbols
if string - it shows maximum number of symbols

FLAGS:

*/

static void	fill_with_zeros(t_format *current)
{
	current->sharp = 0;
	current->f_width = 0;
	current->space = 0;
	current->zero = 0;
	current->minus = 0;
	current->plus = 0;
	current->period = 0;
	current->format = ft_strnew(1);
	current->format_mod = ft_strnew(3);
}

void		parse_period(t_format *current, char **mods)
{
	if (**mods != '.')
		return ;
	(*mods)++;
	current->period = ft_atoi(*mods);
	if (current->period == 0)
		current->period = -1;
	while (ft_isdigit(**mods))
		(*mods)++;
}

void		parse_xsflags(t_format *current, char mod)
{
	if (mod == '#')
		current->sharp = 1;
	else if (mod == '+')
		current->plus = 1;
	else if (mod == ' ')
		current->space = 1;
	else if (mod == '-')
		current->minus = 1;
	else if (mod == '0')
		current->zero = 1;
}

int			parse_conv(char *mods, t_format *current)
{
	if (ft_strchr(MODSLIST, *mods))
	{
		if (*mods == 'i')
			*mods = 'd';
		(current->format)[0] = *mods;
		return (1);
	}
	return (0);
}

t_format	*parse_modifiers(char *mods, t_format *current)
{
	int i;

	i = 0;
	fill_with_zeros(current);
	while (*mods)
	{
		parse_xsflags(current, *mods);
		parse_period(current, &mods);
		if (ft_isdigit(*mods) && *mods != '0')
		{
			current->f_width = ft_atoi(mods);
			while (ft_isdigit(*mods))
				mods++;
			continue;
		}
		while (*mods && ft_strchr(MODSCHAR, *mods))
		{
			(current->format_mod)[i++] = *mods;
			mods++;
		}
		if (parse_conv(mods, current))
			return (current);
		mods++;
	}
	return (NULL);
}

char	*ft_conncat(char *res, const char *src, int l1, int l2)
{
	char	*toret;
	int		size;

	size = l1 + l2;
	toret = ft_strnew(size);
	if (!toret)
		return (NULL);
	if (res)
	{
		ft_strncpy(toret, res, l1);
		free(res);
	}
	ft_strncpy(toret + l1, src, l2);
	return (toret);
}

t_printf	*init_printf()
{
	t_printf	*all;

	all = malloc(sizeof(t_printf));
	if (!all)
		return (NULL);
	all->pd = 0;
	all->type = 0;
	all->spec = 0;
	all->flag = 0;
	all->res = NULL;
	return (all);
}
int		result(t_printf *all, const char *format)
{
	int		i;
	// char	*temp;
	
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			all->res = ft_conncat(all->res, format, all->pd, i);
			all->pd += i;
			format += i + 1;
			i = apply_format(&format, )
			i = 0;
		}
		else
			i++;
	}
	i = ft_strlen(format);
	all->res = ft_conncat(all->res, format, all->pd, i);
	all->pd = i;
	return (all->pd);
}

int		ft_printf(const char *format, ...)
{
	t_printf	*all;
	int			size;

	all = init_printf();
	va_start(all->ap, format);
	size = result(all, format);
	write(1, all->res, size);
	free(all->res);
	va_end(all->ap);
	return (size);
}

/*
**	Source: https://www-user.tu-chemnitz.de/~heha/petzold/ch02c.htm
**	A note on capital letter (wide) conversion types: "Nothing about Unicode
**	or wide characters alters the meaning of the char data type in C. The char
**	continues to indicate 1 byte of storage, and sizeof(char) continues to
**	return 1. In theory, a byte in C can be greater than 8 bits, but for most
**	of us, a byte (and hence a char) is 8 bits wide.
**
**	Wide characters in C are based on the "wchar_t" data type, which is defined
**	in several headers files, including "<wchar.h>", like so:
**	"typedef unsigned short wchar_t;"
**
**	Thus, the "wchar_t" data type is the same as an unsigned short integer:
**	16 bits wide.
**
**	Source: The C Programming Language, 2nd Edition (Dennis Ritchie), page 137
**	&&
**	Source: C Primer Plus 6th Edition, page 113
**
**	*******************************Mandatory Part*******************************
**	Types of conversions:
**
**	s S p d D i o O u U x X c C
**	s: Print characters from the string until a '\0' or the number of
**	characters given by the precision
**
**	S: Equivalent of "%ls"
**
**	p: Pointer
**
**	d: Signed decimal integer
**
**	D: Equivalent of "%ld"
**
**	i: Equivalent of 'd'
**
**	o: Unsigned octal number (without a leading zero)
**
**	u: Unsigned decimal number
**
**	U: Equivalent of "%lu"
**
**	x: Unsigned hexadecimal number (without a leading 0x), using abcdef
**	for 10, ..., 15.
**
**	X: Unsigned hexadecimal number (without a leading 0X), using ABCDEF
**	for 10, ..., 15.
**
**	c: Single character
**
**	C: Equivalent of "%lc"
**
**	Length modifiers:
**	Modifier		d, i			o, u, x, X			n
**	hh				signed char		unsigned char		signed char *
**	h				short			unsigned short		short *
**	l				long			unsigned long		long *
**	ll				long long		unsigned long long	long long *
**	j				intmax_t		uintmax_t			intmax_t *
**	z				(see note)		size_t				(see note)
**
**	Flags:
**	#: A "#" character sepcifies that the value should be printed in
**	"alternate" form.
**	This option has no effect on "b, c, d, s," and "u" formats.
**	For the o formats, the precision of the number increases to make the first
**	character of the outputted string to be zero.
**	For the x/X format, a non-zero string has the string 0x/0X prepended to it.
**	For "a, A, e, E, f, F, g, and G formats", the result always has a decimal.
**	For "g and G" formats, trailing zeros are not removed from the result as
**	they usually would be.
**	0: A "0" character indicates that zero-padding should be used rather than
**	blank padding. A "-" overrides a "0" if both are used. If a numeric
**	conversion is given (d, i, o, u, i, x, and X), then the '0' flag is ignored.
**	-: A "-" sign specifies left adjusment of the output.
**	+: A "+" character specifies that there should always be a sign placed
**	before the number when using signed formats.
**	_: A space specifies that a blank should be left before before a positive
**	number for a signed format. A "+" overrides a space if both are used.
*/
char	*ft_copy(char *res, const char *src, size_t l1, size_t l2)
{
	char	*copy;
	size_t	size;

	size = l1 + l2;
	copy = ft_strnew(size);
	if (!copy)
		return (NULL);
	if (res)
	{
		ft_strncpy(copy, res, l1);
		free(res);
	}
	ft_strncpy(copy + l1, src, l2);
	return (copy);
}

void	save_percent(char **format, va_list arguments)
{
	char	*perc;
	int		i;

	*res = ft_copy(*res, format);
	apply_format(&format, &temp, ap);
	*res = ft_copy(*res, temp;
	total_len += i;
}

int		ft_printf(const char *format, ...)
{
	va_list arguments;
	int		nb_ch;
	char	*res;

	res = NULL;
	nb_ch = 0;
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
			save_percent(&format, arguments);
		else
			format++;
	}
	*res = (*res, format, nb_ch, ft_strlen(format));
	nb_ch += ft_strlen(format);
	while (res)
	{
		ft_putchar(res++);
		nb_ch++;
	}
	free(res);
	va_end(arguments);
	return ((int)nb_ch);
}
