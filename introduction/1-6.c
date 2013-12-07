#include<stdio.h>

int main()
{
	int d;
	scanf("%d", &d);
	int m = d % 10 * 100 + d / 10 % 10 * 10 + d/100;
	printf("%03d\n", m);
	//printf("%d%d%d\n", d % 10, d / 10 % 10, d/100);
	return 0;
}
