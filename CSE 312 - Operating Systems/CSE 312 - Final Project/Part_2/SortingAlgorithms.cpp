#include "SortingAlgorithms.h"

pthread_mutex_t SortingAlgorithms::sort_mutex;

void * SortingAlgorithms::bubbleSort(void * arg) {
	char threadName[32] = "BubbleSort";

	MemoryManager * manager = (MemoryManager *) arg;
	manager->initPhase(threadName);
	int size = manager->getVirtualSize();

	int start = 0;
	int end = size / 2; // N

	for (int i = start; i < end - 1; i++) {
		for (int j = start; j < start + end - i - 1; j++) {
			pthread_mutex_lock(&SortingAlgorithms::sort_mutex);
			int x = manager->get(j, threadName);
			int y = manager->get(j + 1, threadName);
			if (x > y) {
				manager->set(j, y, threadName);
				manager->set(j + 1, x, threadName);
			}
			pthread_mutex_unlock(&SortingAlgorithms::sort_mutex);
		}
	}

	pthread_exit((void *) NULL);
}


