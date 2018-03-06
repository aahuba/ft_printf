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
#include "./libft/libft.h"
#include <stdio.h> /* delete printf */
# define ARG "sSpd%DioOuUxXcC"
# define FLAG "lhjz"
# define SKIP "1234567890sSpd%.DioOuUxXcClhjz#0 -+"

int		ft_printf(const char *type, ...);

#endif
