#include "PageReplacementAlgorithms.h"

void PageReplacementAlgorithms::NRU(PageTable * pTable){
	PageTableEntry * entries = pTable->getEntries();
	for(int i = 0 ; i < pTable->getSize(); i++){
		if(entries[i].referenced == false){
			pTable->setEntryToReplace(i);
			break;
		}
	}
	
}
void PageReplacementAlgorithms::FIFO(PageTable * pTable){

	pTable->setEntryToReplace(pTable->getOldestPageNum());

	pTable->setOldestPageNum(pTable->getOldestPageNum()+1);
	if(pTable->getOldestPageNum() == pTable->getSize()){
		pTable->setOldestPageNum(0);
	}
}
void PageReplacementAlgorithms::SC(PageTable * pTable){

	PageTableEntry * entries = pTable->getEntries();

	while(entries[pTable->getSCPointer()].secondChance == true){
		entries[pTable->getSCPointer()].secondChance = false;
		pTable->setSCPointer((pTable->getSCPointer() + 1) % pTable->getSize());
	}
		
	pTable->setEntryToReplace(pTable->getSCPointer());
		
	
}
void PageReplacementAlgorithms::LRU(PageTable * pTable){

	PageTableEntry * entries = pTable->getEntries();
	int LRUPageNum = 0;
	for(int i = 0 ; i < pTable->getSize(); i++){
		if(entries[i].accessTime < entries[LRUPageNum].accessTime){
			LRUPageNum = i;
		}
	}
	pTable->setEntryToReplace(LRUPageNum);
}
void PageReplacementAlgorithms::WSCLOCK(int timer, PageTable * pTable){

}