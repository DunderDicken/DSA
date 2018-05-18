
#include <stdio.h>

#include "load_file.h"

int main( int argc, char* argv[] )
{
	const char* fName = "C:\Users\dickk\source\repos\DSA\DsaLabs\dsaLab2\sorting_problems\test-10-1-problem";
	
	int* a = load_file(fName);

	int size = a[0];
	for ( int i = 1 ; i <= size ; i++ ) // note this loops from 1 <= i <= size
	{
		printf("%d\n", a[i]);
	}
}
