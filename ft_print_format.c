#include"ft_printf.h"
#include"libft/libft.h"
int ft_print_format(t_print tab, char *format, int pos)
{
	int	i;

	i = 0;
	if (format[pos] == 'c')
	{
		ft_putchar_fd(va_arg(tab->args, int), 1);
		i++;	
	}
	else if (format[pos] == 's')
		i +=ft_print_str(tab); 
	else if (format[pos] == 'p')
		i += ft_print_ptr(tab);
	else if (format[pos] == 'd' || format[pos] == 'i')
		i += ft_print_int(tab);
	else if (format[pos] == 'u')
		i += ft_print_unint(tab);		
	else if (format[pos] == 'x')
		i += ft_hex_format(tab, 0);
	else if (format[pos] == 'X')
		i += ft_hex_format(tab, 32);
	else
	{
		//return (-1);
		// caso non valido
	}
}

int	ft_print_str(t_print *tab)
{
	char *str;

	str = va_arg(tab->args, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_print_hex(int nbr, int offset)
{
	int	il;

	il = 1;
	if (nbr == 0)
		return (0);
	il += ft_print_hex(nbr / 16, offset);
	if(nbr % 16 > 9)
		ft_putchar_fd((nbr % 16 - 10) + ('a' - offset), 1);
	else
		ft_putchar_fd((nbr % 16) + '0', 1);
	return (il);
}

int	ft_hex_format(t_print *tab, int up_flag)
{
	int	val;
	int	i;

	i = 0;
	val = va_arg(tab->args, int);
	if (tab->hastag && up_flag && val != 0)
	{
		ft_putstr_fd("0X", 1);
		i += 2;
	}
	else if (tab->hastag && !up_flag && val != 0)
	{
		ft_putstr_fd("0x", 1);
		i += 2;
	}
	i += ft_print_hex(val, up_flag);
	return i;
	
}

int	ft_print_hexptr(unsigned long long nbr)
{
	int	i;

	i = 1;
	if (nbr == 0)
		return (0);
	il += ft_print_hex(nbr / 16, offset);
	if(nbr % 16 > 9)
		ft_putchar_fd((nbr % 16 - 10) + 'a', 1);
	else
		ft_putchar_fd((nbr % 16) + '0', 1);
	return (i);
}

int	ft_print_ptr(t_print *tab)
{
	int	i;
	unsigned long long val;

	val = va_arg(tab->args, unsigned long long);
	ft_putstr_fd("0x", 1);
	i += 2;
	if (val == 0)
	{
		ft_purchar_fd('0', 1);
		i++;
	}
	else
		i += ft_print_hexptr(val);
	return (i);
}

int	ft_print_unint(t_print *tab)
{
	unsigned int	val;
	int	i;
	
	val = va_arg(tab->args, unsigned int);
	ft_putstr_fd(ft_itoa(val), 1);
	return (ft_strlen(ft_itoa(val)));
}

int	ft_print_int(t_print *tab)
{
	int	i;
	int	val;
	int	len;

	i = 0;
	val = va_arg(tab->args, int);
	len = ft_strlen(ft_itoa(val));
	if (tab->sign)
	{
		if (val > 0)
		{
			ft_putchar_fd('+', 1);
			i++;
		}
	}
	else if (tab->sp)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putstr_fd(ft_itoa(val), 1);
	return (i + len);
}
/*
void ft_print_char(t_print *tab)
{
	char	c;
	c = (char)va_arg(tab->args, int);
	ft_putchar_fd(va_arg(tab->args, int), 1);
}*/
