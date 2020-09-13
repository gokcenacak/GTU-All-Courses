#include "Phase.h"

Phase::Phase(char * name) {
	strcpy(this->name, name);
	numWrites = 0;
	numWrites = 0;
	numReads = 0;
	pageMiss = 0;
	pageReplacements = 0;
	diskPageWrite = 0;
	diskPageRead = 0;
}

Phase::~Phase() {

}
