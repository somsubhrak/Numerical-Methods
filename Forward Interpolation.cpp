#include <stdio.h>
#include <iostream>

int main()
{
    int i, j, n;
    float** y, * x, h, xn, u, res, p;

    printf("Enter the number of elements: ");
    scanf_s("%d", &n);

    x = (float*)malloc(n * sizeof(float));
    y = (float**)malloc(n * sizeof(float*));

    for (i = 0; i < n;i++)
        y[i] = (float*)malloc(n * sizeof(float));

    printf("Enter values of x and y: \n");

    for (i = 0; i < n;i++)
    {
        scanf_s("%f", &x[i]);
        scanf_s("%f", &y[i][0]);
    }

    h = x[1] - x[0];

    for (i = 1;i < n;i++)
    {
        if (x[i] - x[i - 1] != h)
        {
            printf("The values are not equally distributed.\n");

            for (i = 0; i < n; i++)
                free(y[i]);
            free(x);
            free(y);
            return 0;
        }
    }

    for (j = 1;j < n;j++)
        for (i = 0; i <n-j;i++)
            y[i][j] = y[i+1][j-1] - y[i][j - 1];

    printf("The forward difference table is: \n");

    for (i = 0;i < n;i++)
    {
        for (j = 0;j < n - i;j++)
            printf(" %.3f ", y[i][j]);
        printf("\n");
    }

    printf("\nEnter the value of x: ");
    scanf_s("%f", &xn);

    u = (xn - x[0]) / h;
    res = y[0][0];
    p = 1.0;

    for (i = 1;i < n;i++)
    {
        p *= (u - i + 1) / i;
        res += p * y[0][i];
    }

    printf("The value of y at x = %.3f is %.3f\n", xn, res);

    free(x);
    for (i = 0; i < n; i++)
        free(y[i]);
    free(y);

    return 0;
}

/*
30 0.5
35 0.5736
40 0.6428
45 0.7071
50 0.7660
55 0.8192
*/