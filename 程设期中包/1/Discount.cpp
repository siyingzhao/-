#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
    int number;
    double price, discount, pay;
    scanf("%d %lf", &number, &price);
    double total_price = number * price;
    int discount_count = total_price / 100;
    discount = discount_count * 20.0;
    pay = total_price - discount;
    printf("%.2lf %.2lf\n", discount, pay);
    return 0;
}