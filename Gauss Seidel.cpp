// Gauss Seidel.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>


int isDiagonal(float** a, int n)
{
    int i, j;
    float sum;

    for (i = 0;i < n;i++)
    {
        sum = 0.0;
        for (j = 0;j < n;j++)
            if (i != j)
                sum += fabs(a[i][j]);
        if (fabs(a[i][i]) <= sum)
            return 0;
    }
    return 1;
}

int main()
{
    float** a, * x;
    int i, j, k, n, iteration;

    printf("Enter number of equations: ");
    scanf_s("%d", &n);
    
    x = (float*)malloc(n * sizeof(float));
    a = (float**)malloc(n * sizeof(float*));
    for(i= 0; i<n ;i++)
        a[i] = (float*)malloc((n+1) * sizeof(float));
    
    printf("Enter adjacency matrix: ");
    for (i = 0; i < n;i++)
        for (j = 0;j <= n;j++)
            scanf_s("%f", &a[i][j]);

    for (i = 0;i < n;i++)
        x[i] = 0.0;

    if (!isDiagonal(a, n))
    {
        printf("Equations are not diagonally dominant. Gauss Seidel method cannot be applied");
        for (i = 0;i < n;i++)
            free(a[i]);
        free(a);
        return 0;
    }

    printf("System is diagonally dominant\n");
    printf("Enter number of iterations: ");
    scanf_s("%d", &iteration);

    for (k = 0; k < iteration; k++)
    {
        for (i = 0;i < n;i++)
        {
            float sum = a[i][n];
            for (j = 0; j < n;j++)
                if (i != j)
                    sum -= a[i][j] * x[j];
            x[i] = sum / a[i][i];
        }
    }

    printf("Solutions\n");
    for (i = 0; i < n;i++)
        printf("x%d = %.3f\n", i + 1, x[i]);

    for (i = 0;i < n;i++)
        free(a[i]);
    free(a);
    free(x);
}

