#ifndef PAGEREPLACEMENTALGORITHMS
#define PAGEREPLACEMENTALGORITHMS

#include "PageTable.h"
#include <iostream>

class PageReplacementAlgorithms
{
public:
	static void NRU(PageTable * pTable);
	static void FIFO(PageTable * pTable);
	static void SC(PageTable * pTable);
	static void LRU(PageTable * pTable);
	static void WSCLOCK(int timer, PageTable * pTable);
};

#endif