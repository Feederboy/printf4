/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_check_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:58:15 by maquentr          #+#    #+#             */
/*   Updated: 2021/09/06 18:55:55 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_args_for_specific_tests(t_args *args, int d)
{
	if (args->has_width && args->has_prec && d ==0 && (args->prec == -1 || args->prec == 0))
		args->prec_null = 1; //pour %5.0i et 5.i   avec i = 0
	if (args->has_width == -1 && d == 0)
		args->res += ft_putchar('0');
	if (args->has_width && args->width == 1 && d != 0)
	{
		args->has_width = 0;
		args->width = -1;
	}
}

int	ft_conv_check_args_putchar_return_res(t_args *args, int d)
{
	if (!args->has_star_width && args->has_star_prec && args->star_prec < 0 && d == 0)
	{
		args->res += ft_putchar('0');
		return (1);
	}
	if (args->has_prec && args->prec == -1 && d == 0 && args->has_star_width && args->star_width > -1) // pour %*.d -2,0
	{
		while (args->wid-- > 0)
			args->res += ft_putchar(' ');
		return (1);
	}
	if ((args->width > 0 || args->star_width > 0) && (args->has_prec || args->has_star_prec) &&
			(args->prec == 0 || args->star_prec == 0) && d == 0) // pour %*.*d  -2, 0, 5
		// A METTRE DANS UNE FONCTION ET FAIRE UNE FCT CHECK QUI LES REGROUPE TOUTES
	{
		while (args->wid-- > 0)
			args->res += ft_putchar(' ');
		return (1);
	}
	return (0);
}

void	ft_conv_d_negative(t_args *args, int d)
{
	if (d < 0)
	{
		if ((args->len - 1) < args->precision)
			args->padding = (args->precision - (args->len - 1));
		else
			args->padding = 0;
	}
	else
	{
		if (args->len < args->precision)
			args->padding = (args->precision - args->len);
		else
			args->padding = 0;
	}
}


int		ft_conv_du_ifzero_ifelse(t_args *args, int d)
{
		if (args->has_prec || args->has_star_prec)
		{
			while ((args->wid - args->len) > 0)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
			args->res += ft_put_d_zero(d, args);
			return (1);
		}
		else
		{
			if (d < 0)
			{
				if ((args->len - 1) < args->wid)
					args->padding = (args->wid - args->len);
				else
					args->padding = 0;
			}
			else
			{
				if (args->len < args->wid)
					args->padding = (args->wid - args->len);
				else
					args->padding = 0;
			}
			args->res += ft_put_d_zero(d, args);
			return (1);
		}
}

int		ft_conv_du_ifminus(t_args *args, int d)
{

	args->res += ft_put_d_zero(d, args);
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	return (args->res);
}


