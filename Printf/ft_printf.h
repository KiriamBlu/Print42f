/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:29:08 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/10/21 12:31:22 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int					ft_printf(const char *str, ...);
int					ft_translate(va_list args, char c, int len);
int					print_char(char c, int len);
int					print_str(char *str, int len);
int					print_freeze(char *str, int len);
int					printvoid(void *ptr, int len, int type);
size_t				len(unsigned int n, int sign);
char				*itoa(int n, int sign);
char				*itoa_hexa(unsigned long int n, char *base, int type);
unsigned long int	lenhexa(unsigned long int n);

#endif