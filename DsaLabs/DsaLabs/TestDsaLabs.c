//This is a test
#include <stdio.h>
#define ARRAY_SIZE 100

int main() {
	int a[ARRAY_SIZE];
	int c = 0;

	
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		c++;
		printf("%d,  ", c);
	}

	if (c == ARRAY_SIZE)
	{
		printf("True! %d    ",c);
	}

	return 0;
}


