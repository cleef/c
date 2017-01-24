#include<stdio.h>

int main()
{

	int a,b,c;
	scanf("%d%d%d", &a,&b,&c);
	int min = a, max = a;
	if(b < min)
             min = b;
	if(c < min)
             min = c;
	if(b > max)
             max = b;
	if(c > max)
             max = c;

	int mid = a + b + c - min - max;
        printf("%d %d %d\n", min,mid,max);
	return 0;
}

