/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:08:04 by matt              #+#    #+#             */
/*   Updated: 2021/12/19 13:00:30 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_args
{
	int	c;
	int	width;
	int	has_width;
	int	prec;
	int	has_prec;
	int	minus;
	int	has_zero;
	int	zero;
	int	has_star_width;
	int	star_width;
	int	has_star_prec;
	int	star_prec;
	int	percent;
	int	wid;
	int	precision;
	int	padding;
	int	len;
	int	prec_null;
	int	res;
	int	a;
}				t_args;

//UTILS
char	*ft_itoa_base(long n, char *base);
int		ft_strlen(char *s);
char	*ft_strchr(char *str, char c);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putstrl(char *str, int len);
int		ft_isdigit(char c);
int		ft_atoi(const char *str);
int		ft_nb_digits(int d);
int		ft_nb_digits_unsigned(unsigned int d);
int		get_nb_size(int base, long long n);
int		get_nb_size2(int base, uint64_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa_base(long n, char *base);
char	*ft_ultoa_base(uint64_t n, char *base);
void	getnb(char **result, char *base, long long n, int pos);
void	getnb2(char **result, char *base, uint64_t n, int pos);
int		ft_nb_dig(char *str);

//CONV
int		ft_printf(const char *format, ...);
int		ft_put_d(t_args *args, va_list ap);
int		ft_put_d_zero(int d, t_args *args);
int		ft_put_i(t_args *args, va_list ap);
int		ft_put_i_zero(int d, t_args *args);
int		ft_put_p_zero(char *str, t_args *args);
int		ft_put_p(t_args *args, va_list ap);
int		ft_put_x_zero(char *str, t_args *args);
int		ft_put_x(t_args *args, va_list ap);
int		ft_put_big_x(t_args *args, va_list ap);
int		ft_put_s(t_args *args, va_list ap);
int		ft_put_c(t_args *args, va_list ap);
int		ft_put_u(t_args *args, va_list ap);
int		ft_put_u_checks(t_args *args, unsigned int d);
int		ft_put_u_zero(unsigned int d, t_args *args);
void	ft_conv_d_negative(t_args *args, int d);
void	ft_conv_p_negative(t_args *args, long long s);
void	ft_conv_x_negative(t_args *args, long s);
int		ft_conv_d_ifzero_ifelse(t_args *args, int d);
void	ft_conv_d_ifzero_else(t_args *args, int d);
void	ft_print_width(t_args *args);
int		ft_conv_p_ifzero_ifelse(t_args *args, char *tmp, long long s);
int		ft_conv_x_ifzero_ifelse_bis(t_args *args, char *tmp, long s);
int		ft_conv_x_ifzero_ifelse(t_args *args, char *tmp, long s);
int		ft_conv_x_has_prec(t_args *args, char *tmp, long s);
void	ft_print_space(t_args *args);
int		ft_free_and_return(t_args *args, char *res);
int		ft_free_and_return_bis(t_args *args, char **res);
int		ft_return_checks(t_args *args, long d);
int		ft_return_checks_bis(t_args *args, long d, char *res);
int		ft_zero_and_minus(t_args *args, char *res, long d);
int		ft_zero_and_minus_bis(t_args *args, char *res, long d);
int		ft_conv_x_else_prec(t_args *args, char *tmp, long s);
int		ft_conv_d_ifminus(t_args *args, int d);
int		ft_conv_p_ifminus(t_args *args, char *tmp);
int		ft_pminus(t_args *args, char *res);
int		ft_pminusbis(t_args *args);
int		ft_conv_x_ifminus(t_args *args, char *tmp, long d);
int		ft_conv_u_ifzero_ifelse(t_args *args, unsigned int d);
void	ft_conv_u_ifelse_bis(unsigned int d, t_args *args);
int		ft_conv_u_ifminus(t_args *args, unsigned int d);
int		ft_conv_u_ifzero_ifelse(t_args *args, unsigned int d);
int		ft_put_pct(t_args *args, va_list ap);
void	ft_conv_pct_ifzero(t_args *args);
void	ft_conv_pct_ifminus(t_args *args);
void	ft_conv_pct_elsezero(t_args *args);
int		ft_set_args_s(t_args *args, char *s);
void	ft_if_minus(t_args *args, char *s);
int		ft_else_minus(t_args *args, char *s);

//Checkings
int		ft_check_full_zero(t_args *args, int d);
int		ft_check_full_zero_bis(t_args *args, int d, char *res);
int		ft_check_full_zero_bis_bis(t_args *args, int d, char **res);
int		ft_check_full_zero_long(t_args *args, long d);
int		ft_check_full_zero_long_return(t_args *args, uint64_t s, char *res);
int		ft_check_prec_null_int(t_args *args, int d);
int		ft_check_prec_null_long(t_args *args, long d);

//SET
void	ft_set_args_for_specific_tests(t_args *args, int d);
int		ft_conv_check_args_putchar_return_res(t_args *args, int d);
void	ft_setprec_with_X_null(t_args *args);
int		ft_set_all_args(t_args *args, long d);
void	ft_set_all_args_bis(t_args *args);
int		ft_set_args_regrouped(t_args *args, long d);
char	*ft_set_prefix(char *str);
char	*ft_set_res_ultoa_prefix(t_args *args, char *res, uint64_t s);

//ARGS
void	init_args(t_args *args);
char	*read_minus_zero_minus(t_args *args, char *itr);
char	*read_starwidth_width(t_args *args, char *itr, va_list ap);
char	*read_prec_starprec_prec(t_args *args, char *itr, va_list ap);
char	*read_digit(t_args *args, char *itr);
void	ft_init_width_prec_starwid_starprec(t_args *args);
#endif
