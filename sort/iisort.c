#include <stdio.h>

////////////////// int version /////////////////

void iswap(int *a, int i, int j)
{
	int k = a[i];
	a[i] = a[j];
	a[j] = k;
}

void iisort(int *a, int n)
{
	int i, j;
	for (i = 1; i < n; i++)
		for(j = i; j > 0 && a[j-1] > a[j]; j--)
		{
			iswap(a, j, j-1);
		}
}

////////////////// generic version /////////////////
int intcomp(int *i, int *j) {return *i - *j;}

void swap(char *i, char *j, int n)
{
	do 
	{
		char c = *i;
		*i++ = *j;
		*j++ = c;
	} while (--n > 0);
}

void isort(char *a, int n, int es, int (*cmp)())
{
	char *pi, *pj;
	for(pi = a + es; pi < a + n*es; pi +=es)
	       for(pj = pi; pj > a && cmp(pj-es, pj) > 0; pj -=es)
	       		swap(pj, pj - es, es);	       

}

int main(int argc, char *argv[])
{
	int array[10] = {1, 6, 3, 10, 5, 7, 9, 8, 4, 2};
	//iisort(array, 10);
	isort( (char *) array, 10, sizeof(int), intcomp);
	int i;
	for (i = 0; i < 10; i++)
		printf("%d", array[i]);
}
