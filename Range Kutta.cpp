#include <iostream>
float f(float x, float y)
{
    return (3 * x + y * y);
 }

int main()
{
    float x, y, h, xn, k;
    printf("Enter value of x, y and step length: ");
    scanf_s("%f %f %f", &x , &y, &h);
    printf("Enter value of x for which you want to find y: ");
    scanf_s("%f", &xn);

    while (x < xn)
    {
        float k1 = h * f(x, y);
        float k2 = h * f(x + h/2.0, y + k1/2.0);
        float k3 = h * f(x + h/2.0, y + k2/2.0);
        float k4 = h * f(x + h, y + k3);
        k = (k1 +  k2 + k3 + k4) / 4.0;
        y += k;
        x += h;
    }
    printf("Value of y = %.3f", y);
    return 0;
}
