#include <stdio.h>
#include <math.h>

double ft_fast_bin_pow(double a, int b)
{
	double res;

	res = 1;
	while (b)
	{
		if (b & 1)
			res *= a;
		a *= a;
		b >>= 1;
	}
	return (res);
}

double T0(double u)
{
	return (1);
}
double T1(double u)
{
	return (u);
}
double T2(double u)
{
	return (2 * u * u - 1);
}
double T3(double u)
{
	return (4 * ft_fast_bin_pow(u, 3) - 3.0 * u);
}
double T4(double u)
{
	return (8.0 * ft_fast_bin_pow(u, 4) - 8.0 * u * u + 1.0);
}
double T5(double u)
{
	return (16.0 * ft_fast_bin_pow(u, 5) - 20.0 * ft_fast_bin_pow(u, 3) + 5.0 * u);
}



int main()
{
	int i = 0;
	double a = -0.5;
	double b = 0.5;
	double x[6];
	double u[6] = {0.96592582628, 0.70710678118, 0.2588190451, -0.2588190451, -0.70710678118, -0.96592582628};
	double y[6];
	double c0 = 0;
	double c1 = 0;
	double c2 = 0;
	double c3 = 0;
	double c4 = 0;
	double c5 = 0;

	while (i < 6)
	{
		x[i] = (b - a) / 2 * u[i] + (a + b) / 2;
		++i;
	}
	i = 0;
	while (i < 6)
	{
		y[i] = sin(3.14159265 * x[i]);
		++i;
	}
	i = 0;
	while (i < 6)
	{
		c0 += y[i];
		++i;
	}
	c0 = 2 * c0 / 6;
	while (i < 6)
	{
		c0 += T0(u[i]) * y[i];
		++i;
	}
	c0 = 2 * c0 / 6;
	i = 0;
	while (i < 6)
	{
		c1 += T1(u[i]) * y[i];
		++i;
	}
	i = 0;
	c1 = 2 * c1 / 6;
	while (i < 6)
	{
		c2 += T2(u[i]) * y[i];
		++i;
	}
	i = 0;
	c2 = 2 * c2 / 6;
	while (i < 6)
	{
		c3 += T3(u[i]) * y[i];
		++i;
	}
	i = 0;
	c3 = 2 * c3 / 6;
	while (i < 6)
	{
		c4 += T4(u[i]) * y[i];
		++i;
	}
	i = 0;
	c4 = 2 * c4 / 6;
	while (i < 6)
	{
		c5 += T5(u[i]) * y[i];
		++i;
	}
	c5 = 2 * c5 / 6;
	printf("%.10lf\n%.10lf\n%.10lf\n%.10lf\n%.10lf\n%.10lf\n", c0, c1, c2 , c3, c4, c5);
	return (0);
}