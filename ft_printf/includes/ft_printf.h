/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:38:09 by ahuba             #+#    #+#             */
/*   Updated: 2018/02/05 15:38:12 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <libft.h>
#include <stdio.h> /* delete printf */
# define TYPE "sSpd%DioOuUxXcC"
# define SPEC "lhjz"
# define FLAG "#0 -+"
# define SKIP "1234567890sSpd%.DioOuUxXcClhjz#0 -+"

typedef struct	s_printf
{
		int		pd; // printed
		int		type; // type sSpd%DioOuUxXcC
		int		spec; // specificator lhjz
		int		flag; // #0 -+
		char	*res; // result
		va_list	ap;

}				t_printf;

int		ft_printf(const char *format, ...);

#endif
