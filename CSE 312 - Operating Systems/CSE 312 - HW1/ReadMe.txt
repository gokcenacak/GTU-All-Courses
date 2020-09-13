CSE 312 - Operating Systems Homework #1 ReadMe

Gökçe Nur Erer - 171044079

This homework implements 5 assembly files including:

	1)ShowDivisibleNumbers.asm

	Takes 3 integer values from user, one is the starting number, one is the ending number and the last one is the 
	number to check if the numbers in between the starting and the ending numbers are divided by it.

	2)LinearSearch.asm

	The array to do the search on, the size of the array and the target number to be searched are given in the assembly file at the .data segment.
	Program outputs the array, the target number and the index of the target number that is returned by the linear search algorithm.


	3)BinarySearch.asm

	The array to do the search on, the size of the array and the target number to be searched are given in the assembly file at the .data segment.
	Program outputs the array, the target number and the index of the target number that is returned by the binary search algorithm.

	4)SelectionSort.asm

	The array to do the sorting and the size of the array is given in the assembly file at the .data segment.
	Program outputs the unsorted array and the sorted array sorted by selection sort.

	5)Shell.asm

	Program takes program names (WITHOUT the .asm extension) as user input and if their .asm file exist it loads and executes it. 
	Once the loaded program is executed and finished the control is given back to shell. The shell runs infinitely until "exit" command is entered.
	If user tries to load a program that does not exist shell simply just warns the user and does not try to execute that file. 
	Program uses syscall CreateProcess which has the code of 18.

	--PS: In assembly files LinearSearch, BinarySearch assumed that the indexes start from 0.--

Also this homework implements syscall.cpp and syscall.h file:

	Changes at syscall.h: Added the new syscall CreateProcess with the code 18.

	Changes at syscall.cpp: Implemented the new syscall CreateProcess. First it backups all the register and memory information to a struct. Then the current register and
				memory information is cleared for the new process to run. Then SPIM is reinitialized and the assembly file requested to run is loaded.
				If it is loaded the execution of the file starts. If not an error message is printed. After the execution the backup that was taken from the beginning is
				restored in the registers and memory so that the previous process can run again. 
