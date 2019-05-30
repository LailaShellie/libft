/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:31:51 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/30 14:31:52 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.Trash/libft_git/libft.h"
#include <stdlib.h>

void	ft_free_mas(unsigned int ***mas, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		free(*mas);
		++i;
	}
	free(*mas);
	*mas = 0;
}
