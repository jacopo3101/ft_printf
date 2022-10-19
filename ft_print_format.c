#include"ft_printf.h"
#include"libft/libft.h"
/*int ft_print_format(t_print tab, char *format, int pos)
{
	if (format[pos] == 'c')
	{
		
		code 
		ft_print_char(tab);
		
	}
	else if (format[pos] == 's')
	{
		 code
		ft_print_str();
		 
	}
	else if (format[pos] == 'p')
	{
		 code 
		ft_print_ptr();
		
	}
	else if (format[pos] == 'd' || format[pos] == 'i')
	{
		 code
		ft_print_int();
		 
	}
	else if (format[pos] == 'u')
	{
		 code 
		ft_print_unsint();
		
	}
	else if (format[pos] == 'x')
	{
		 code 
		ft_print_hex();
		
	}
	else if (format[pos] == 'X')
	{
		 code 
		ft_print_hex();
		
	}
	else
	{
		//return (-1);
		// caso non valido
	}
}*/

/*int	ft_validate_int(t_print *tab)
{
	if (tab->dash == 1 && tab->zero == 1)
	{
		tab->zero = 0;
	}
}*/

void	ft_print_hex(int nbr)
{
	if (nbr == 0)
		return ;
	ft_print_hex(nbr / 16);
	if(nbr % 16 > 9)
		ft_putchar_fd((nbr % 16 - 10) + 'a', 1);
	else
		ft_putchar_fd((nbr % 16) + '0', 1);
}

void	ft_print_int(t_print *tab)
{
	int	i;
	int	val;
	int	len;

	i = 0;
	len = ft_strlen(ft_itoa(val));
	val = va_arg(tab->args, int);
	if (tab->wdt > 0)
	{
		if(tab->dash == 1)
		{
			ft_putchar_fd(ft_itoa(val), 1);
			while (tab->wdt < i + len)
			{
				ft_putstr_fd(' ', 1);
				i++;
			}
		}
		else
		{
			if (tab->zero == 1)
			{
				while (tab->wdt < i + len)
				{
					ft_putchar_fd('0', 1);
					i++;
				}
				ft_putstr_fd(ft_itoa(val), 1);
			}
			else
			{
				while (tab->wdt < i + len)
				{
					ft_putstr_fd(' ', 1);
					i++;
				}
				ft_putchar_fd(ft_itoa(val), 1);
			}
		}
	}
	else if (tab->prc > 0)
	{
		if//only ' '
	}
	else
	{
		
	}
}
void ft_print_char(t_print *tab)
{
	char	c;
	int	i;

	i = 0;
	c = (char)va_arg(tab->args, int);
	
	if (tab->wdt > 0)
	{
		if (tab->dash == 1)
		{
			ft_putchar_fd(c, 1);
			while (i < tab->wdt - 1)
			{
				ft_putchar_fd(' ', 1);
				i++;
			}
		}
		else
		{
			while (i < tab->wdt - 1)
			{
				ft_putchar_fd(' ', 1);
				i++;
			}
			ft_putchar_fd(c, 1);
		}
	}
	else
		ft_putchar_fd(c, 1);
}

void	ft_print_spaces()
{
	
}


