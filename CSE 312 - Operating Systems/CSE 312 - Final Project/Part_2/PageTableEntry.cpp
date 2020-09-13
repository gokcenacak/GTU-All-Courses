#include "PageTableEntry.h"

void PageTableEntry::initializePTEntry(int virtualFrameNum, bool referenced, bool modified, int time, bool secondChance){
	this->virtualFrameNum = virtualFrameNum;
	this->referenced = referenced;
	this->modified = modified;
	this->accessTime = time;
	this->secondChance = secondChance;
}
PageTableEntry::PageTableEntry(){
	virtualFrameNum = -1;
	accessTime = 0;
	secondChance = 0;
}
PageTableEntry::~PageTableEntry(){
	
}
