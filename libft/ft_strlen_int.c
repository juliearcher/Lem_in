/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen_int(int nb, int base)
{
	unsigned	nbr;
	int			length;

	length = 1;
	if (nb < 0)
		++length;
	nbr = nb < 0 ? -nb : nb;
	while ((nbr = nbr / base) != 0)
		++length;
	return (length);
}
