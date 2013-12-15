#include<stdio.h>
#include<math.h>

int main()
{
    const double pi = atan(1)*4;
    double f = sin(pi);
    int n = 10;
	printf("%.8lf\n", f);
	printf("%.8lf\n", 1+2*sqrt(3)/(5-0.1));
	return 0;
}
