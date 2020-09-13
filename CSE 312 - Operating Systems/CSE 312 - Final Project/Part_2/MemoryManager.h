#ifndef MEMORYMANAGER
#define MEMORYMANAGER

#include "Phase.h"
#include "PageReplacementAlgorithms.h"
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

enum PageReplacementAlgorithm{ NRU, FIFO, SC, LRU, WSCLOCK };

class MemoryManager
{
public:
	MemoryManager(int frameSize, int numPhysical, int numVirtual, char * replacementAlgorithm, char * allocPolicy, int pageTablePrintInt, char * diskFileName);
	~MemoryManager();
	void set(unsigned int index, int value, char * tName);
	int get(unsigned int index, char * tName);
	int existInPhysicalMemory(int frameNum);
	void printPhysicalMemory();
	PageTable * getPageTable() { return pageTable; }
	void writeToDisk(int frameNum);
	int getVirtualSize();
	void setReplacementAlgorithm(char * name);
	void initPhase(char * phaseName);
	int getPhaseIndex(char * phaseName);
	void printPhases();
	void setPrintInterval(int interval) { printInterval = interval; }

private:
	int frameSize;
	int numPhysical;
	int numVirtual;
	char pageReplacement[10];
	char allocPolicy[10];
	int pageTablePrintInt;
	char diskFileName[256];
	int * physicalMemory;
	PageTable * pageTable;
	int timer;
	PageReplacementAlgorithm algorithm;
	std::vector<Phase> phases;
	pthread_mutex_t mutex;
	int printInterval;
};

#endif