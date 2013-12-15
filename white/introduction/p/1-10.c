#include<stdio.h>

int main()
{
    int d;
    scanf("%d", &d);
    if((d % 4) == 0)
    {
        if( (d % 100) == 0 && (d % 400) != 0)
            printf("no\n");
        else
            printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}
