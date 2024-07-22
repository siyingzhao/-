#include <stdio.h>
#pragma warning(disable:4996)

float conversion_3(float E)
{
    float e;
    int k;
    k = (int)(1000 * E);
    e = (float)k / 1000.0;
    return e;
}

int main()
{
    float a, b, c, d, e, f, g, h, i, j, k, m;
    scanf("%f %f %f %f %f %f %f %f %f %f %f %f", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &m);
    printf("%-6.3f %-6.3f\n", conversion_3(a), conversion_3(b));
    printf("%-6.3f %-6.3f\n", conversion_3(c), conversion_3(d));
    printf("%-6.3f %-6.3f\n", conversion_3(e), conversion_3(f));
    printf("%6.2f %6.2f %6.2f\n", g, h, i);
    printf("%6.2f %6.2f %6.2f", j, k, m);
    return 0;
}