#ifndef SORTINGALGORITHMS
#define SORTINGALGORITHMS

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include "MemoryManager.h"

class SortingAlgorithms
{
public:
	static void * bubbleSort(void * arg);
	
	static pthread_mutex_t sort_mutex;
};

#endif