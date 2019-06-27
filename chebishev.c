#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "libft.h"

double		u_to_x(double u, double a, double b)
{
	return (u * (b - a) / 2 + (a + b) / 2);
}

double		x_to_u(double x, double a, double b)
{
	return ((2 * x - a - b) / (b - a));
}

double		Tn(double u, int n)
{
	if (n == 0)
		return (1);
	else if (n == 1)
		return (u);
	return (2 * u * Tn(u, n - 1) - Tn(u, n - 2));
}

double		f_x(double x, double *c, double a, double b, int n)
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

void		get_nodes(int n, double *u)
{
	int i;

	i = 0;
	while (i < n)
	{
		u[i] = cos((2 * (i + 1) - 1) * 3.14159265 / (2 * n));
		++i;
	}
}

int			main()
{
	int i = 0;
	int j;
	double a = -0.5;
	double b = 0.5;
	int n = 8;
	double y[n];
	double c[n];
	double u[n];

	get_nodes(n, u);
	i = 0;
	while (i < n)
	{
		y[i] = sin(3.14159265 * u_to_x(u[i], a, b));
		++i;
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c[i] += Tn(u[j], i) * y[j];
			++j;
		}
		if (!i)
			c[i] = c[i] / n;
		else
			c[i] = 2 * c[i] / n;
		++i;
	}
//	i = 0;
//	while (i < n)
//	{
//		printf("%.20lf\n", c[i]);
//		++i;
//	}
	double x = 90;
	printf("sin(%.2lf) = %lf\n", x, ft_sin(x));
	return (0);
}