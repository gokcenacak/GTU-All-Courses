all: clean sortArrays

sortArrays: sortArrays.o PageTable.o PageReplacementAlgorithms.o PageTableEntry.o SortingAlgorithms.o MemoryManager.o Phase.o
		g++ -std=c++11 sortArrays.o PageTable.o PageReplacementAlgorithms.o PageTableEntry.o SortingAlgorithms.o MemoryManager.o Phase.o -lpthread -o sortArrays
sortArrays.o: sortArrays.cpp
		g++ -c -std=c++11 sortArrays.cpp
MemoryManager.o: MemoryManager.cpp
		g++ -c -std=c++11 MemoryManager.cpp
PageReplacementAlgorithms.o: PageReplacementAlgorithms.cpp
		g++ -c -std=c++11 PageReplacementAlgorithms.cpp
PageTable.o: PageTable.cpp
		g++ -c -std=c++11 PageTable.cpp
PageTableEntry.o: PageTableEntry.cpp
		g++ -c -std=c++11 PageTableEntry.cpp
SortingAlgorithms.o: SortingAlgorithms.cpp
		g++ -c -std=c++11 SortingAlgorithms.cpp
Phase.o: Phase.cpp
		g++ -c -std=c++11 Phase.cpp
clean:
	rm -f *.o sortArrays