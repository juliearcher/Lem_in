/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <wchar.h>
# include "libft/libft_printf.h"
# include "libft.h"

# define NB_FLAGS		7
# define NB_FLAGS_TAB	5
# define NB_CONV		19

# define LONG			3

enum			e_flags
{
	SHARP,
	ZERO,
	MINUS,
	PLUS,
	SPACE
};

typedef struct	s_printf
{
	char		*flags;
	int			flags_tab[NB_FLAGS_TAB];
	char		*flags_type[NB_FLAGS];
	char		*conv;
	int			(*f[NB_CONV])();

	int			min_width;
	int			precision;
	int			type;

	const char	*format;
	char		*output;
	int			output_length;
	int			length;
	int			prev;
	va_list		ap;
}				t_printf;

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_printf_loop(t_printf *str, int fd);

int				init_struct(t_printf *str);
void			init_flags_tab(t_printf *str);

void			set_flags(t_printf *str);
void			set_min_width(t_printf *str);
void			set_precision(t_printf *str);
void			set_length_modifier(t_printf *str);

int				printf_conversion(t_printf *str);

int				print_precision(t_printf *str, int length);
int				print_width(t_printf *str, int length);

int				printf_string(t_printf *str);
int				printf_string_unicode(t_printf *str);
int				printf_addr(t_printf *str);
int				printf_int(t_printf *str);
int				printf_long_int(t_printf *str);
int				printf_octal(t_printf *str);
int				printf_long_octal(t_printf *str);
int				printf_unsigned(t_printf *str);
int				printf_long_unsigned(t_printf *str);
int				printf_lower_hexa(t_printf *str);
int				printf_upper_hexa(t_printf *str);
int				printf_char(t_printf *str);
int				printf_char_unicode(t_printf *str);
int				printf_percent(t_printf *str);
int				printf_binary(t_printf *str);
int				printf_long_binary(t_printf *str);
int				printf_float(t_printf *str);
int				printf_long_double(t_printf *str);
int				print_number_base(t_printf *str, char *base,
									char *prefix, int size);

uintmax_t		get_number_unsigned(t_printf *str);
intmax_t		get_number(t_printf *str);
long double		get_float(t_printf *str);

#endif
