#include<stdio.h>

int main()
{
	int n, m, x, y;
	scanf("%d%d", &n, &m);
        y = m / 2 - n;
	x = n - y;
        if(y > 0 && x > 0 && m % 2 == 1)	
		printf("%d %d\n", x, y);
	else
		printf("No answer\n");
}
