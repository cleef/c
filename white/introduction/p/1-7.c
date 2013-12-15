#include<stdio.h>

int main()
{
    const float price = 95;
    int n;
    scanf("%d", &n);
    float cost = n * price;
    if(cost > 300)
        cost = cost * 0.95;
    printf("%.2f\n", cost);

}
