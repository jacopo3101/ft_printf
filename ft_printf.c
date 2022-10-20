/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:41:32 by javellis          #+#    #+#             */
/*   Updated: 2022/10/14 10:41:35 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>

t_print	*ft_initialise_tab(t_print *tab)                       
{                       
	tab->wdt = 0;	// we set everything to 0, false
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->tl = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->sp = 0;
	return (tab);
}

void	ft_print_tab(t_print *tab)                       
{
	printf("wdt = %d\n",tab->wdt);    
	printf("prc = %d\n",tab->prc);                    
	printf("zero = %d\n",tab->zero);                        
	printf("pnt = %d\n", tab->pnt);                      
      printf("sign = %d\n",tab->sign);                      
	printf("tl = %d\n",tab->tl);                    
      printf("is_zero = %d\n",tab->is_zero);                      
      printf("dash = %d\n",tab->dash);                  
      printf("perc = %d\n",tab->perc);                      
      printf("sp = %d\n",tab->sp);            
}

int ft_format(t_print *tab, char *format, int pos)
{
	char *charset;
	//char *charset2;

	charset = ft_strdup("cspdiuxX");
	//charset2 = ft_strdup("-. %+0123456789");
	while(format[pos] && !ft_checkchr(charset, format[pos]) )
	{
		if (format[pos] == '-')  // - 0 . # ' ' + (Minimmum width)
		{
			tab->dash = 1;
			pos++;
		}
		else if (format[pos] == '.')
		{
			tab->pnt = 1;
			pos++;
		}
		else if (format[pos] == ' ')
		{
			tab->sp = 1;
			pos++;
		}
		else if (format[pos] == '%')
		{
			tab->perc = 1;
			pos++;
		}
		else if (format[pos] == '+')
		{
			tab->sign = 1;
			pos++;
		}
		else if (format[pos] == '0')
		{
			tab->sign = 1;
			pos++;
		}
		else if (format[pos] == '#')
		{
			tab->hastag = 1;
			pos++;
		}
		else if (ft_isdigit(format[pos]) && format[pos] != 0)
		{
			pos = ft_strtonum(pos, format, tab);
		}
		/*else
		{
			// non stampare niente
			// ft_print_format();
		}*/
	}
	//printf("\ni = %d\n", pos);
	//ft_print_tab(tab);
	ft_print_int(tab);
	return (pos + 1);
}

int		ft_printf(const char *format, ...)
{
	t_print *tab;
	int i;
	int res;

	i = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	va_start(tab->args, format);
	if (!tab)
		return (-1);
	tab = ft_initialise_tab(tab);
	while(format[i])
	{
	
		if (format[i] == '%')
		{
			i = ft_format(tab, (char *)format, i + 1);
			tab = ft_initialise_tab(tab);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			res++;
			i++;
		}
	}
	// WIP
	return 5;

}

int main()
{
	ft_printf("#%10d#", 55);
}
