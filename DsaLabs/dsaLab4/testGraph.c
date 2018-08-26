/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>

/*INCLUDE MY FILES*/
#include "LinkedList.h"
#include "GraphList.h"

#include "testGraphList.h"
#include "testGraphMatrix.h"

#define NUM_OF_VERTICES 4

int main(int argc, char* argv[])
{
	//Test for Execrcise 1 
	//testGraphMatrix();

	//Test for Excercise 2
	testGraphConnectivity();

	getchar();
}
