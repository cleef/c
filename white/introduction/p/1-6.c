#include<stdio.h>

int main()
{
   int d;
   scanf("%d", &d);
   if (d % 2 == 0)
       printf("yes\n");
   else
       printf("no\n");
   if ( (d & 1) == 0)
       printf("yes\n");
   else
       printf("no\n");
}
