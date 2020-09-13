#ifndef PAGETABLEENTRY
#define PAGETABLEENTRY

class PageTableEntry
{
public:
	PageTableEntry();
	void initializePTEntry(int virtualFrameNum, bool referenced, bool modified, int time, bool secondChance);
	~PageTableEntry();
	int virtualFrameNum;
	bool referenced;
	bool modified;
	int accessTime;
	bool secondChance;
};

#endif