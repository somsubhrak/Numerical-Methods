
#include <iostream>
#include <stdio.h>

int main()
{
    int n, i;
    float* x, * y;
    double a, b, sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    printf("Enter the number of data points: ");
    scanf_s("%d", &n);

    x = (float*)malloc(n * sizeof(float));
    y = (float*)malloc(n * sizeof(float));

    printf("Enter the values of x and y:\n");
        
    for (i = 0;i < n;i++)
    {
        scanf_s("%f %f", &x[i], &y[i]);
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;

    printf("The equation is y = %.2lf + %.2lfx\n", a, b);

    free(x);
    free(y);
    return 0;

}
/*
1.2 8.4
2.3 14.2
3.1 17.3
4.5 23.5
5.7 30.2
*/
