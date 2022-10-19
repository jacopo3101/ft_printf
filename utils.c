/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:55:30 by javellis          #+#    #+#             */
/*   Updated: 2022/10/14 15:55:34 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include<unistd.h>
#include<stdio.h>
int	ft_checkchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int ft_strtonum(int pos, char *format, t_print *tab)
{
	int	i;
	char	*nbr;

	i = 0;
	while(ft_isdigit(format[pos + i]))
		i++;
	nbr = ft_substr(format, pos, i);
	if (tab->pnt == 1)
	{
		tab->prc = ft_atoi(nbr);
	}
	
	tab->wdt = ft_atoi(nbr);
	return (pos + i);
}
