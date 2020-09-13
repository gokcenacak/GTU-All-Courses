#ifndef PHASE
#define PHASE

#include <cstring>

class Phase
{
public:
	Phase(char * name);
	~Phase();

	char name[32];
	int numWrites;
	int numReads;
	int pageMiss;
	int pageReplacements;
	int diskPageWrite;
	int diskPageRead;
};

#endif