#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int main()
{
	FILE *f_in;
	int a, b, c;
	char o;
	scanf("%d %c %d", &a, &o, &b);
	switch (o)
	{
		case '+':
			c = a + b;
			break;
		case '-':
			c = a - b;
			break;
	}
	system("pause");
	return 0;
}