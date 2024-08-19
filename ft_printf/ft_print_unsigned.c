/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmachlou <mmachlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:12:41 by mmachlou          #+#    #+#             */
/*   Updated: 2024/06/27 14:23:13 by mmachlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int num)
{
	char			*value;
	int				len;

	len = ft_num_len(num);
	value = (char *)malloc(sizeof(char) * (len + 1));
	if (!value)
		return (NULL);
	value[len] = '\0';
	if (num == 0)
	{
		value[0] = '0';
		return (value);
	}
	len--;
	while (num > 0)
	{
		value[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (value);
}

int	ft_print_unsigned(unsigned int num)
{
	char	*value;
	int		print_len;

	print_len = 0;
	if (num == 0)
		print_len += write(1, "0", 1);
	else
	{
		value = ft_uitoa(num);
		if (value)
		{
			print_len += ft_printstr(value);
			free(value);
		}
	}
	return (print_len);
}
