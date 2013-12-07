#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a;
	char *b = malloc(10 * sizeof(char));
	scanf("%d%s", &a, b);
	printf("%d %s\n", a, b);

	return 0;
}
