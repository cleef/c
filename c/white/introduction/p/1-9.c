#include<stdio.h>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int max = a, min = a;
    if(b > max)
        max = b;
    if(c > max)
        max = c;
    if(b < min)
        min = b;
    if(c < min)
        min = c;
    int middle = a + b + c - max - min;
    if(min + middle > max)
    {
        if(max * max == (min * min + middle * middle))
            printf("yes\n");
        else
            printf("no\n");
    }
    else
    {
        printf("not a triangle\n");
    }


}
