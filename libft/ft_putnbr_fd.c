/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	print_nbr(unsigned int nb, int fd)
{
	if (nb >= 10)
		print_nbr(nb / 10, fd);
	ft_putchar_fd(nb % 10 + 48, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
		write(fd, "-", 1);
	nb = n >= 0 ? n : -n;
	print_nbr(nb, fd);
}
