#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <pthread.h>
#include "MemoryManager.h"
#include "SortingAlgorithms.h"

void * fill(void * arg)
{
	char threadName[32] = "Fill";

	MemoryManager * manager = (MemoryManager *) arg;
	manager->initPhase(threadName);
	int size = manager->getVirtualSize();

	srand(1000);
	for (int i = 0; i < size; i++) {
		int randNum = rand() % 100;
		manager->set(i, randNum, threadName);
	}

	pthread_exit((void *) NULL);
}

void * check(void * arg) {
	char threadName[32] = "Check";

	MemoryManager * manager = (MemoryManager *) arg;
	manager->initPhase(threadName);
	int size = manager->getVirtualSize();

	bool isFirstHalfSorted = true;
	for (int i = 0; i < size / 2 - 1; i++) {
		int first = manager->get(i, threadName);
		int second = manager->get(i + 1, threadName);
		if (first > second) {
			isFirstHalfSorted = false;
		}
	}

	bool isSecondHalfSorted = true;
	for (int i = size / 2; i < size - 1; i++) {
		int first = manager->get(i, threadName);
		int second = manager->get(i + 1, threadName);
		if (first > second) {
			isSecondHalfSorted = false;
		}	
	}

	if (isFirstHalfSorted) {
		std::cout << "First half is sorted" << std::endl;
	}

	if (isSecondHalfSorted) {
		std::cout << "Second half is sorted" << std::endl;
	}

	if (isFirstHalfSorted && isSecondHalfSorted) {
		std::cout << "Memory is sorted" << std::endl;
	} else {
		std::cout << "Memory is not sorted" << std::endl;
	}

	pthread_exit((void *) NULL);
}

int main(int argc, char const *argv[])
{
	srand(1000);
	if(argc != 8){
		std::cout << "Usage: sortArrays frameSize numPhysical numVirtual pageReplacement allocPolicy pageTablePrintInt diskFileName.dat" << std::endl;
	}

	// parsing arguments
	int frameSize = atoi(argv[1]);
	int numPhysical = atoi(argv[2]);
	int numVirtual = atoi(argv[3]);

	char pageReplacement[10];
	strcpy(pageReplacement,argv[4]);
	char allocPolicy[10];
	strcpy(allocPolicy,argv[5]);

	int pageTablePrintInt = atoi(argv[6]);

	char diskFileName[256];
	strcpy(diskFileName, argv[7]);

	// Creating memory manager
	MemoryManager manager(frameSize, numPhysical, numVirtual, pageReplacement, allocPolicy, pageTablePrintInt, diskFileName);
	manager.setReplacementAlgorithm(pageReplacement);
	manager.setPrintInterval(pageTablePrintInt);
	// Fill thread
	pthread_t fillThreadID;
	pthread_create(&fillThreadID, NULL, fill, (void *) &manager);
	void * fillThreadReturnValue;
	pthread_join(fillThreadID, &fillThreadReturnValue);

	// Bubble sort thread
	pthread_mutex_init(&SortingAlgorithms::sort_mutex, NULL);
	pthread_t bubbleSortThreadID;
	pthread_create(&bubbleSortThreadID, NULL, SortingAlgorithms::bubbleSort, (void *) &manager);
	void * bubbleSortThreadReturnValue;
	pthread_join(bubbleSortThreadID, &bubbleSortThreadReturnValue);
	pthread_mutex_destroy(&SortingAlgorithms::sort_mutex);

	// Check thread
	pthread_t checkThreadID;
	pthread_create(&checkThreadID, NULL, check, (void *) &manager);
	void * checkThreadReturnValue;
	pthread_join(checkThreadID, &checkThreadReturnValue);

	manager.printPhases();
	return 0;
}