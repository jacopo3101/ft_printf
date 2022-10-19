/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:32:12 by javellis          #+#    #+#             */
/*   Updated: 2022/10/04 10:32:17 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_print
{
	va_list  args;		//# arg to print out                    
	int   wdt;		//# width                
	int   prc;		//# precision              
	int   zero;		//# zero padding               
	int   pnt;		//# .     
	int   dash;		//# -               
	int   tl;		//# total_length (return value)              
	int   sign;		//# pos or neg number               
	int   is_zero;		//# is number zero                 
	int   perc;		//# %               
	int   sp;		//# space flag ' '            
}	t_print;

int	ft_checkchr(const char *s, char c);
int	ft_strtonum(int pos, char *format, t_print *tab);
int	ft_print_format(t_print tab, char *format, int pos);
t_print	*ft_initialise_tab(t_print *tab);
int	ft_format(t_print *tab, char *format, int pos);
int	ft_printf(const char *format, ...);
void	ft_print_char(t_print *tab);

#endif
