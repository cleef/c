#include<stdio.h>

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d %d\n", b, a); 
       
	int t = a;
	a = b;
	b = t;
	printf("%d %d\n", a, b); 

        a = a + b;
	b = a - b;
	a = a - b;
	printf("%d %d\n", a, b); 
        
	a^=b^=a^=b;
	printf("%d %d\n", a, b); 
	return 0;
}

