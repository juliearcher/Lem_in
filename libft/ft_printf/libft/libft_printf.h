/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdint.h>
# include <wchar.h>
# include "../ft_printf.h"

typedef struct s_printf	t_printf;

int				ft_strlen_unsigned(uintmax_t nb, int base);
int				*ft_strlen_float_unsigned(long double nb, int *tab, int max);
void			ft_putnbr_unsigned_base(uintmax_t nb, char *base,
					unsigned int size, t_printf *str);
size_t			ft_strlen_unicode(const wchar_t *str, int precision);
void			ft_putchar_printf(char c, t_printf *str);
void			ft_putstr_printf(char *str, t_printf *s);
void			ft_putchar_unicode(wchar_t c, t_printf *str);

#endif
