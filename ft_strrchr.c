/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:52:24 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/10 14:06:56 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	sym;

	ptr = 0;
	sym = c;
	while (1)
	{
		if (*s == sym)
		{
			ptr = (char *)s;
		}
		if (*s == '\0' && sym == 0)
			return ((char *)s);
		if (*s == '\0')
			return (ptr);
		++s;
	}
}
