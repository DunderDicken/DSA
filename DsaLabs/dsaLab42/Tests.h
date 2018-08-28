#pragma once

/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>

/*INCLUDE MY FILES*/
#include "Graph.h"

/* TESTS */

void test();

void EX1();

void EX2();

void EX4();

void EX5();

/* UTILITY FUNCTIONS */

void createUnwantedList(List* L);

void removeUnwanted(Graph* G, int target);
