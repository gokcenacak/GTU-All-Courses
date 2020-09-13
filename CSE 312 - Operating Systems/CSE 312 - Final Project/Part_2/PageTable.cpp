#include "PageTable.h"
PageTable::PageTable(int size){
	entries = new PageTableEntry[size];
	this->size = size;
	isEmpty = true;
	isFull = false;
	currentSize = 0;
	SCPointer = 0;
}
PageTable::~PageTable(){
	delete [] entries;
}
void PageTable::addEntry(unsigned int virtualFrameNum, bool referenced, bool modified, int time, bool secondChance){
	if(isEmpty == true){
		oldestPageNum = 0;
		isEmpty = false;
		entries[currentSize].initializePTEntry(virtualFrameNum, referenced, modified, time, secondChance);
		currentSize++;
		entryToReplace = currentSize;
	}
	else{

		if(currentSize != size-1){

			entries[currentSize].initializePTEntry(virtualFrameNum, referenced, modified,time, secondChance);
			currentSize++;
			entryToReplace = currentSize;

		}
		else{
			isFull = true;
			entries[entryToReplace].initializePTEntry(virtualFrameNum, referenced, modified,time, secondChance);
		}

	}
	

}


void PageTable::print(){
	std::cout << "=======================================================================" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << "Virtual Frame Num: " << entries[i].virtualFrameNum << " Referenced:" << entries[i].referenced << " Modified:" << entries[i].modified << " Access Time:" << entries[i].accessTime << " SC:" << entries[i].secondChance << std::endl;
	}
	std::cout << "=======================================================================" << std::endl;
}

PageTableEntry * PageTable::getEntry(int index){
	return &entries[index];
}

void PageTable::resetReferenced(){

	for(int i = 0; i < size; i++){
		entries[i].referenced = false;
	}
}