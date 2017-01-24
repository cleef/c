#include<stdio.h>

int main()
{
    int a = 0, b = 1, c = 1;
    printf("%d\n", !a&&b);
    printf("%d\n", a&&b||c);
    printf("%d\n", (a&&b)||c);
    printf("%d\n", a&&(b||c));

    int x = 0, y = 0;
    if(a)
    	{
	    if(b)
		    x++;
     	    else
		    y++;
	}
    printf("%d %d\n", x, y);

}
