
#include<stdio.h>
#include<math.h>

int main()
{
    int i, j;
    for(i = 1; i <= 9; i++)
    {
        for(j = 0; j <=9; j++)
        {
            int d = i * 1100 + j * 11;
            double s = sqrt(d);
            if(floor(s + 0.5) == s)
                printf("%d %f\n", d, s);
        }
    }
}
