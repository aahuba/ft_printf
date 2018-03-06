/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:35:16 by ahuba             #+#    #+#             */
/*   Updated: 2018/01/29 14:36:40 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		main(void)
{
	int		p;
	int		f;

	// /* UA */
	// printf("UA\n");
	// p =	printf("фів\n");
	// f = ft_printf("фів\n");
	// printf("p: %d\nf: %d\n", p, f);
	// printf("UA\n");

	// /* ENG */
	// printf("\nENG\n");
	// p =	printf("asd\n");
	// f = ft_printf("asd\n");
	// printf("p: %d\nf: %d\n", p, f);
	// printf("ENG\n");

	// /* CH */
	// printf("\nCH\n");
	// p =	printf("迪克\n");
	// f = ft_printf("迪克\n");
	// printf("p: %d\nf: %d\n", p, f);
	// printf("CH\n");

	// p = printf("ORIG: \t[%+8s]\n", "Coconut");
	// f =	ft_printf("MINE: \t[%+8s]\n");
	// printf("p: %d\nf: %d\n", p, f);
	// p = printf("%%");
	// f = ft_printf("%%");
	// printf("p: %d\nf: %d\n", p, f);
	// f = ft_printf("MINE>\t[%%]\n", 25, 16215);
	p = printf("[%%%] \n");
	f = ft_printf("[%%%] \n");
	printf("p: %d\nf: %d\n", p, f);
	return (0);
}