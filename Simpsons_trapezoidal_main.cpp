#include <stdio.h>
#include <math.h>

double f(double x)
{
	return (x)*sin(x) + x * x * x;
}

int main() {
	double a, b, h, x, sum;
	int n, ch = 1, i;
	printf("Enter lower limit, upper limit, and number of intervals: ");
	scanf_s("%lf %lf %d", &a, &b, &n);


	h = (b - a) / n;

	printf("1: Trapezoidal\n2: Simpson's ");
	while (ch)
	{
		printf("\nEnter choice: ");
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1: {
			sum = f(a) + f(b);
			for (i = 1; i < n; i++)
			{
				x = a + i * h;
				sum += 2 * f(x);
			}
			sum *= (h / 2.0);
			printf("\nTrapezoidal: %lf", sum);
			break;
		}
		case 2: {
			if (n % 2 != 0)
			{
				printf("Number of intervals should be even for Simpson's rule.\n");
				return 1;
			}
			sum = f(a) + f(b);
			for (i = 1; i < n; i++)
			{
				x = a + i * h;
				sum += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
			}
			sum *= (h / 3.0);
			printf("\nSimpson's: %lf", sum);
			break;
		}
		default:
			printf("Invalid choice");
		}
	}

	return 0;
}