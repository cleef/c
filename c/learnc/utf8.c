#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
	char* c = {"主要就是想试试给咱们寄信时地址可以写的多简略"};
	//char ch[] = { 228, 184, 187, 0 };
	//const char *c = ch;
	while(*c)
	{
		unsigned char ch = ((unsigned char) *c++);
		printf("%d\n", ch);
		//printf("%c",*c++);
	}
	printf("\n");
}
