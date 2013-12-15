#include<stdio.h>
#include<math.h>

int main()
{
    const double pi = atan(1)*4;
    int n;
    scanf("%d", &n);
    printf("%.3f\n", cos(pi*n/180));
    printf("%f\n", sin(pi*n/180));
}

