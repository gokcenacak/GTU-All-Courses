#ifndef PAGETABLE
#define PAGETABLE

#include "PageTableEntry.h"
#include <iostream>

class PageTable
{
public:
	PageTable(int size);
	PageTableEntry * getEntry(int frameNum);
	PageTableEntry * getEntries() { return entries; }
	void addEntry(unsigned int virtualFrameNum, bool referenced, bool modified, int time, bool secondChance);
	void print();
	inline int getEntryToReplace() { return entryToReplace; }
	inline int getOldestPageNum() { return oldestPageNum; }
	inline void setOldestPageNum(int num) { oldestPageNum = num; }
	inline void setEntryToReplace(int num) { entryToReplace = num;}
	inline void setSCPointer(int index) { SCPointer = index;}
	inline int getSCPointer() { return SCPointer; }
	inline int getSize() { return size; }
	inline bool shouldReplace() { return isFull; }
	void resetReferenced();
	~PageTable();


private:
	PageTableEntry * entries;
	bool isEmpty;
	bool isFull;
	int entryToReplace;
	int size;
	int currentSize;
	int oldestPageNum;
	int SCPointer;
};

#endif