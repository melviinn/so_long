/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:01:22 by mduchauf          #+#    #+#             */
/*   Updated: 2023/11/13 12:01:23 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_sc
{
	int	len;
	int	width;
}				t_sc;

int			ft_printf(const char *format, ...);

const char	*ft_find_args(va_list args, const char *format, t_sc *sc);
const char	*ft_read_str(t_sc *sc, const char *format);

void		ft_write_char(va_list args, t_sc *sc);
void		ft_write_string(va_list args, t_sc *sc);
void		ft_write_decimal(va_list args, t_sc *sc);
void		ft_write_hexa(va_list args, t_sc *sc);
void		ft_write_uphexa(va_list args, t_sc *sc);
void		ft_write_unsigned(va_list args, t_sc *sc);
void		ft_write_percent(t_sc *sc);
void		ft_write_ptr(va_list args, t_sc *sc);

void		ft_putchar(int c);
void		ft_putstr(char *s);
void		ft_puthexa(unsigned int x);
void		ft_putaddr(void *ptr);

size_t		ft_strlen_2(char const *s);
size_t		ft_count_digits(int n);
size_t		ft_count_digits_hexa(unsigned int x);

#endif