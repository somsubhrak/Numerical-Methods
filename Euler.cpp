#include <stdio.h>

float f(float x, float y)
{
	return (3 * x + y * y);
}
int main()
{
	float x, y, h, xn;
	printf("Enter value of x, y and step size: ");
	scanf_s("%f %f %f", &x, &y, &h);
	printf("Enter value of x for which you want to find y: ");
	scanf_s("%f", &xn);

	while (x < xn)
	{
		y += h * f(x, y);
		x += h;
	}
	printf("\nValue of y at x = %f is %.3f: ", xn, y);
	return 0;
}