#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define BUF_SIZE 33

char *int2bin(int a, char *buffer, int buf_size) {
	buffer += (buf_size - 1);

	int i = 31;
	for (; i >= 0; i--) {
	       *buffer-- = (a & 1) + '0';
	       a >>= 1;
        }
        return buffer;
}


int main()
{
	char buffer[BUF_SIZE];
	buffer[BUF_SIZE - 1] = '\0';

	int min, max;

	//min = 1 << (8 * sizeof(int) - 1);
	//max = ~(1 << (sizeof(int) -1));
        max = (unsigned)-1 >> 1;
	min = max + 1;
	int2bin(min, buffer, BUF_SIZE - 1);
	printf("min = %s\n", buffer);

	int2bin(max, buffer, BUF_SIZE - 1);
	printf("max = %s\n", buffer);

        printf("%d %d\n", min, max);
	return 0;
}
