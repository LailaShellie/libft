/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:58:47 by lshellie          #+#    #+#             */
/*   Updated: 2019/06/27 17:58:51 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double		Tn(double u, int n)
{
	if (n == 0)
		return (1);
	else if (n == 1)
		return (u);
	return (2 * u * Tn(u, n - 1) - Tn(u, n - 2));
}

static double		x_to_u(double x, double a, double b)
{
	return ((2 * x - a - b) / (b - a));
}

static double		f_x(double x, double *c, double a, double b, int n)
{
	int i = 0;
	double res = 0;

	while (i < n)
	{
		res += c[i] * Tn(x_to_u(x, a, b), i);
		++i;
	}
	return (res);
}

double				ft_sin(double alpha)
{
	double x;
	double a;
	double b;
	int n;
	double c[8];

	n = 8;
	a = -0.5;
	b = 0.5;
	c[0] = 0;
	c[1] = 1.13364817640860993109;
	c[2] = 0;
	c[3] = -0.13807177875741061257;
	c[4] = 0;
	c[5] = 0.00449071486854682456;
	c[6] = 0;
	c[7] = -0.00006829360271105867;
	x = alpha / 180;
	return (f_x(x, c, a, b, n));
}