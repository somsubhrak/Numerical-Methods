// gaussElimination.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  
   int n, i, j, k, flag=1;
   float ** a, *x, *temp, r;
   printf("Enter no. of equations: ");
   scanf_s("%d", &n);

   a = (float**)malloc(sizeof(float*));

   for (i = 0; i < n + 1; i++)
      a[i] = (float*)malloc((n + 1) * sizeof(float));

   x = (float*)malloc(n*sizeof(float));
   temp = (float*)malloc((n+1) * sizeof(float));

   printf("Enter the augmented matrix:\n ");
   for (i = 0; i < n; i++)
      for (j = 0; j < n + 1; j++)
         scanf_s("%f", &a[i][j]);

   if (a[0][0] == 0.0)
   {
      for (i = 0; i < n; i++)
      {
         if (a[i][0] != 0.0)
         {
            for (j = 0; j < n + 1; j++)
            {
               temp[j] = a[0][j];
               a[0][j] = a[i][j];
            }
            for (j = 0; j < n + 1; j++)
               a[i][j] = temp[j];
            break;
         }
      }
   }
  
   printf("Augmented matrix : \n");
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n + 1; j++)
         printf("%.3f ", a[i][j]);
      printf("\n");
   }

   for (k = 0; k < n - 1; k++)
   {
      if (a[k][k] != 0.0)
         for (i = k + 1; i < n; i++)
         {
            r = a[i][k] / a[k][k];
            for (j = 0; j < n + 1; j++)
               a[i][j] = a[i][j] - r * a[k][j];
         }
      else
      {
         flag = 0;
         break;
      }
   }
   if (flag == 1)
   {
      printf("Augmented matrix after transformation: \n");
      for (i = 0; i < n; i++)
      {
         for (j = 0; j < n + 1; j++)
            printf("%.3f ", a[i][j]);
         printf("\n");
      }
      for (i = n - 1; i >= 0; i--)
      {
         x[i] = a[i][n];
         for (j = i + 1; j < n; j++)
            x[i] = x[i] - a[i][j] * x[j];
         x[i] = x[i] / a[i][i];

      }
      printf("Solutions:\n");
      for (i = 0; i < n; i++)
         printf("x[%d] = %.3f ", i + 1, x[i]);
   }
   else
      printf("Gauss Elimination method is not applicable");
   return 0;
}

/*
4 -3 1 -8
-2 1 -3 -4
1 -1 2 2

 1 1 1 4
1 4 3 8
1 6 2 6

0 1 1 3
1 1 1 6
1 2 3 14
*/

