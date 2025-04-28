#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, n;
    float res = 0.0, xn;

    printf("Enter the number of data points: ");
    scanf_s("%d", &n);

    float* x = (float*)malloc(n * sizeof(float));
    float* y = (float*)malloc(n * sizeof(float));

    printf("Enter the values of x and y:");

    for (i = 0; i < n;i++)
        scanf_s("%f %f", &x[i], &y[i]);

    printf("Enter the value of the interpolation point: ");
    scanf_s("%f", &xn);

    for (i = 0; i < n;i++)
    {
        float p = 1.0;
        for (j = 0;j < n;j++)
            if (i != j)
                p *= (xn - x[j]) / (x[i] - x[j]);
        res += p * y[i];
    }
    printf("\nThe value of at %f is: %.3f\n", xn, res);
}

/*
1 2
2 4
3 8
4 6
7 128
*/
