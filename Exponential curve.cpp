
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;

    float **x, sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    printf("Enter the number of data points: ");
    scanf_s("%d", &n);

     x = (float**)malloc(n * sizeof(float*));

    for (i = 0;i < n;i++)
        x[i] = (float*)malloc(2 * sizeof(float));

    printf("Enter the values of x and y:\n");
    for (i = 0;i < n;i++)
        scanf_s("%f %f", &x[i][0], &x[i][1]);
    
    for(i = 0;i < n;i++)
        x[i][1] = log(x[i][1]);

    for (i = 0;i < n;i++)
    {
        sumX += x[i][0];
        sumY += x[i][1];
        sumXY += x[i][0] * x[i][1];
        sumX2 += x[i][0] * x[i][0];
    }
    
    //float a = (sumX2 * sumY - sumX* sumXY) / (n * sumX2 - sumX * sumX);
    float b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    float a = (sumY - b * sumX) / n;
    a = exp(a);

    printf("The equation is y = %.2f e^ %.2fx\n", a, b);

    for (i = 0; i < n; i++)
        free(x[i]);
    free(x);
    return 0;

}
/*
1.2 8.4
2.3 14.2
3.1 17.3
4.5 23.5
5.7 30.2
*/

