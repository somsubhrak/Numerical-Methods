#include <iostream>
#include <stdio.h>

double e;
double f(double x)
{
    return x * x * x - 3 * x - 5;
}

double df(double x)
{
    return 3 * x * x - 3;
}
void bisection()
{
    double a, b, x;
    do
    {
        printf("\nEnter the lower limit and upper limit:");
        scanf_s("%lf %lf", &a, &b);
    } while ((f(a) * f(b)) > 0);
    
    printf("\na\t  b\t  x1\t    f(x)");

    do
    {
        x = (a + b) / 2.0;
        printf("\n%.3lf\t  %.3lf\t %.3lf \t%.3lf", a, b, x, f(x));
        if (f(a) * f(x) < 0.0)
            b = x;
        else
            a = x;
    } while (fabs(a - b) > e);
    printf("\nThe root is:%0.3f\n", x);

}

void regulafalsi()
{
    double a, b, x;
    do
    {
        printf("\nEnter the lower limit and upper limit:");
        scanf_s("%lf %lf", &a, &b);
    } while ((f(a) * f(b)) > 0);

    printf("\na\t  b\t  x1\t   f(x)");

    do
    {
        x = (a * f(b) - b * f(a)) / (f(b)-f(a));

        printf("\n%.3lf\t  %.3lf\t %.3lf \t%.3lf", a, b, x, f(x));
        if (f(a) * f(x) < 0.0)
            b = x;
        else
            a = x;
    } while (fabs(f(x)) > e);
    printf("\nThe root is:%0.3f\n", x);
}

void newton()
{
    double a, x;
    
    printf("\nEnter the interval a:");
    scanf_s("%lf", &a);

    printf("\na\t  x1\t   f(x)");

    do
    {
        x = a - (f(a)/df(a));

        printf("\n%.3lf\t  %.3lf\t %.3lf", a, x, f(x));
        a = x;
    } while (fabs(f(x)) > e);
    printf("\nThe root is:%0.3f\n", x);
}

int main()
{
    printf("Enter tolerance: ");
    scanf_s("%lf", &e);
    printf("1) Bisection\n2)Regula Falsi\nNewtown\n4)0 to exit\n");

    int ch = 1;
    while (ch)
    {
        printf("1)Enter choice: ");
        scanf_s("%d", &ch);
        switch (ch)
        {
        case 1: bisection();
            break;
        case 2: regulafalsi();
            break;
        case 3: newton();
            break;
        default: printf("Wrong choice\n");
            break;
        }
    }
}
