/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_kmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:23:00 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/28 18:23:01 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		*z_func(const char *str)
{
	unsigned int	*z;
	unsigned int	i;
	unsigned int	j;

	if (!(z = (unsigned int *)ft_memalloc(sizeof(int) * ft_strlen(str))))
		return (0);
	z[0] = 0;
	i = 1;
	j = 0;
	while (str[i])
	{
		if (str[i] != str[j] && j == 0)
			z[i] = 0;
		else if (str[i] != str[j] && j != 0)
			j = z[j - 1];
		if (str[i] == str[j])
			z[i] = ++j;
		++i;
	}
	return (z);
}

char				*ft_strstr_kmp(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	*z;
	char			*p;

	z = z_func(needle);
	i = 0;
	j = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != 0)
	{
		p = (char *)(&haystack[i - j]);
		while (haystack[i] == needle[j] && needle[j] != 0)
		{
			++i;
			++j;
		}
		if (needle[j] == 0)
			return (p);
		if (j != 0)
			j = z[j - 1];
		if (j == 0)
			++i;
	}
	return (0);
}