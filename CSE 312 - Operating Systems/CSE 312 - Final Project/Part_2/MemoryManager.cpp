#include "MemoryManager.h"

MemoryManager::MemoryManager(int frameSize, int numPhysical, int numVirtual, 
							 char * pageReplacement, char * allocPolicy, 
							 int pageTablePrintInt, char * diskFileName){

	this->frameSize = pow(2,frameSize);
	this->numPhysical = pow(2,numPhysical);
	this->numVirtual = pow(2,numVirtual);
	strcpy(this->pageReplacement, pageReplacement);
	strcpy(this->allocPolicy, allocPolicy);
	this->pageTablePrintInt = pageTablePrintInt;
	strcpy(this->diskFileName, diskFileName);

	int physicalMemorySize = this->numPhysical * this->frameSize;
	physicalMemory = new int[physicalMemorySize];
	pageTable = new PageTable(this->numPhysical);
	timer = 0;

	std::ofstream diskFile(this->diskFileName);
	for(int i = 0; i < this->numVirtual * this->frameSize; i++){
		diskFile << 0 << "\n";
	}
	diskFile.close();

	pthread_mutex_init(&mutex, NULL);
}

MemoryManager::~MemoryManager(){
	for (int i = 0; i < numPhysical; i++) {
		writeToDisk(i);
	}

	pthread_mutex_destroy(&mutex);
	delete [] physicalMemory;
	delete pageTable;
}

void MemoryManager::set(unsigned int index, int value, char * tName){
	pthread_mutex_lock(&mutex);

	int currentPhaseIndex = getPhaseIndex(tName);
	Phase* currentPhase = &phases[currentPhaseIndex];

	if((currentPhase->numReads + currentPhase->numWrites) % printInterval == 0 ){
		pageTable->print();
	}

	if (currentPhaseIndex == -1) {
		std::cerr << "ERROR! PHASE " << tName << " IS NOT REGISTERED!" << std::endl;
	}

	currentPhase->numWrites++;

	timer++;
	if(timer % 5 == 0){
		pageTable->resetReferenced();
	}
	int frameGroup = index / frameSize;
	int posInPhyMemory = existInPhysicalMemory(frameGroup);

	if(posInPhyMemory != -1){
		pageTable->getEntries()[posInPhyMemory].modified = true;
		pageTable->getEntries()[posInPhyMemory].secondChance = true;

		pageTable->getEntries()[posInPhyMemory].accessTime = timer;
		physicalMemory[posInPhyMemory * frameSize + index % frameSize] = value;
	}
	else{
		currentPhase->pageMiss++;

		std::ifstream diskFile(this->diskFileName);
		int i;
		int temp;
		for(i = 0; i < frameGroup; i++){
			for(int j = 0; j < frameSize ; j++){
				diskFile >> temp;
			}
		}
		int *frame = new int[frameSize];
		for(int j = 0 ; j < frameSize; j++){
			int m;
			diskFile >> frame[j];
		}
		int j = 0;

		if(pageTable->shouldReplace()){
			currentPhase->pageReplacements++;
			currentPhase->diskPageRead++;

			switch(algorithm){
				case PageReplacementAlgorithm::NRU: 	PageReplacementAlgorithms::NRU(pageTable);
					 									break;

				case PageReplacementAlgorithm::FIFO:	PageReplacementAlgorithms::FIFO(pageTable);
														break;

				case PageReplacementAlgorithm::LRU:		PageReplacementAlgorithms::LRU(pageTable);
														break;

				case PageReplacementAlgorithm::SC:		PageReplacementAlgorithms::SC(pageTable);
														break;

				case PageReplacementAlgorithm::WSCLOCK:	PageReplacementAlgorithms::WSCLOCK(timer,pageTable);
														break;

				default:								break;
			}
			if(pageTable->getEntries()[pageTable->getEntryToReplace()].modified == true){
				currentPhase->diskPageWrite++;
				writeToDisk(pageTable->getEntryToReplace());
			}
		}

		for(int i = pageTable->getEntryToReplace() * frameSize; i < pageTable->getEntryToReplace() * frameSize + frameSize; i++){
			physicalMemory[i] = frame[j];
			j++;
		}
		pageTable->addEntry(frameGroup, true, true, timer,true);
		
		delete [] frame;
		diskFile.close();
		physicalMemory[existInPhysicalMemory(frameGroup) * frameSize + index % frameSize] = value;
	}
	pthread_mutex_unlock(&mutex);
}

int MemoryManager::get(unsigned int index, char * tName){
	pthread_mutex_lock(&mutex);

	int currentPhaseIndex = getPhaseIndex(tName);
	Phase* currentPhase = &phases[currentPhaseIndex];

	if((currentPhase->numReads + currentPhase->numWrites) % printInterval == 0){
		pageTable->print();
	}

	if (currentPhaseIndex == -1) {
		std::cerr << "ERROR! PHASE " << tName << " IS NOT REGISTERED!" << std::endl;
	}

	currentPhase->numReads++;
	timer++;
	
	if(timer % 5 == 0){
		pageTable->resetReferenced();
	}
	int frameGroup = index / frameSize;
	int posInPhyMemory = existInPhysicalMemory(frameGroup);

	if(posInPhyMemory != -1){
		pageTable->getEntries()[posInPhyMemory].referenced = true;
		pageTable->getEntries()[posInPhyMemory].secondChance = true;
		pageTable->getEntries()[posInPhyMemory].accessTime = timer;
		pthread_mutex_unlock(&mutex);
		return physicalMemory[posInPhyMemory * frameSize + index % frameSize];
	}
	else{
		currentPhase->pageMiss++;

		std::ifstream diskFile(this->diskFileName);
		int i;
		int temp;
		for(i = 0; i < frameGroup; i++){
			for(int j = 0; j < frameSize ; j++){
				diskFile >> temp;
			}
		}
		int *frame = new int[frameSize];
		for(int j = 0 ; j < frameSize; j++){
			int m;
			diskFile >> frame[j];
		}
		int j = 0;
		
		if(pageTable->shouldReplace()){
			currentPhase->pageReplacements++;
			currentPhase->diskPageRead++;

			switch(algorithm){
				case PageReplacementAlgorithm::NRU: 	PageReplacementAlgorithms::NRU(pageTable);
					 									break;

				case PageReplacementAlgorithm::FIFO:	PageReplacementAlgorithms::FIFO(pageTable);
														break;

				case PageReplacementAlgorithm::LRU:		PageReplacementAlgorithms::LRU(pageTable);
														break;

				case PageReplacementAlgorithm::SC:		PageReplacementAlgorithms::SC(pageTable);
														break;

				case PageReplacementAlgorithm::WSCLOCK:	PageReplacementAlgorithms::WSCLOCK(timer,pageTable);
														break;

				default:								break;
			}
			if(pageTable->getEntries()[pageTable->getEntryToReplace()].modified == true){
				currentPhase->diskPageWrite++;
				writeToDisk(pageTable->getEntryToReplace());
			}
		}

		for(int i = pageTable->getEntryToReplace() * frameSize; i < pageTable->getEntryToReplace() * frameSize + frameSize; i++){
			physicalMemory[i] = frame[j];
			j++;
		}
		pageTable->addEntry(frameGroup, true, false, timer, true);
		
		delete [] frame;
		diskFile.close();
		pthread_mutex_unlock(&mutex);
		return physicalMemory[existInPhysicalMemory(frameGroup) * frameSize + index % frameSize];
	}
}

int MemoryManager::existInPhysicalMemory(int frameNum){
	PageTableEntry * pTable = pageTable->getEntries();
	for(int i = 0 ; i < numPhysical ; i++){
		if(pTable[i].virtualFrameNum == frameNum){
			return i;
		}
	}
	return -1;
}
void MemoryManager::printPhysicalMemory(){
	for(int i = 0; i < numPhysical * frameSize; i++){
		std::cout << physicalMemory[i] << std::endl;
	}
}

void MemoryManager::writeToDisk(int frameNum){
	std::ifstream diskFile(this->diskFileName);

	std::vector<std::string> diskFileContent;
	std::string line;

	while(std::getline(diskFile,line)){
		diskFileContent.push_back(line);
	}
	diskFile.close();

	int virtualFrameNum = pageTable->getEntries()[frameNum].virtualFrameNum;
	virtualFrameNum *= frameSize;

	for(int i = frameNum * frameSize ; i < frameNum * frameSize + frameSize ; i++){
		diskFileContent[virtualFrameNum] = std::to_string(physicalMemory[i]);
		virtualFrameNum++;
	}

	std::ofstream updatedDiskFile(this->diskFileName);
	for(auto line : diskFileContent){
		updatedDiskFile << line << std::endl;
	}
	updatedDiskFile.close();
}

int MemoryManager::getVirtualSize() {
	return frameSize * numVirtual;
}

void MemoryManager::setReplacementAlgorithm(char * name){
	if(strcmp(name,"NRU") == 0){
		algorithm = PageReplacementAlgorithm::NRU;
	}
	else if(strcmp(name,"FIFO") == 0){
		algorithm = PageReplacementAlgorithm::FIFO;
	}
	else if(strcmp(name,"LRU") == 0){
		algorithm = PageReplacementAlgorithm::LRU;
	}
	else if(strcmp(name,"SC") == 0){
		algorithm = PageReplacementAlgorithm::SC;
	}
	else if(strcmp(name,"WSCLOCK") == 0){
		algorithm = PageReplacementAlgorithm::WSCLOCK;
	}
}

void MemoryManager::initPhase(char * phaseName) {
	Phase p(phaseName);
	phases.push_back(p);
}

int MemoryManager::getPhaseIndex(char * phaseName) {
	for (int i = 0; i < phases.size(); i++) {
		if (strcmp(phaseName, phases[i].name) == 0) {
			return i;
		}
	}

	return -1;
}

void MemoryManager::printPhases(){
		std::cout << "=============================PHASES===========================" << std::endl;
	for (int i = 0; i < phases.size(); i++) {
		std::cout << "==============================================================" << std::endl;
		std::cout << "Name: " << phases[i].name << std::endl;
		std::cout << "Number of Writes: " << phases[i].numWrites << std::endl;
		std::cout << "Number of Reads: " << phases[i].numReads << std::endl;
		std::cout << "Number of Page Misses: " << phases[i].pageMiss << std::endl;
		std::cout << "Number of Page Replacements: " << phases[i].pageReplacements << std::endl;
		std::cout << "Number of Disk Page Writes: " << phases[i].diskPageWrite << std::endl;
		std::cout << "Number of Disk Page Reads: " << phases[i].diskPageRead << std::endl;
		std::cout << "==============================================================" << std::endl;

	}
}
