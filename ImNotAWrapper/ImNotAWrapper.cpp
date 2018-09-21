// ImNotAWrapper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <direct.h>
#include <stdio.h>
#include <iostream>

//Convert bytes to MB
#define DIV 1048576

//Method to check no other instance is running, returns false if another instance is found.
bool isOnlyInstance() {
	//Terry your shit goes here, please use toilet paper
	return true;
}

//Method to check if there is enough available storage, outputs to console the results.
void checkStorage(const DWORDLONG diskSpaceNeeded) {
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);

	unsigned __int64 const neededClusters = diskSpaceNeeded /
		(diskfree.sectors_per_cluster * diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters) {
		std::cout << "checkStorage Failure: Not enough physical storage." << std::endl;
	}
	else
		std::cout << "checkStorage Success: You got the cash!." << std::endl;
}

//Method to check how much physical and virtual memory is available on the system.
void checkMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded) {
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);

	if (status.ullAvailPhys < physicalRAMNeeded || status.ullAvailVirtual < virtualRAMNeeded) {
		std::cout << "checkMemory: Get a new computer fam!" << std::endl;
	}
	else {
		std::cout << "checkMemory: You passed the requirements!" << std::endl;
	}

	std::cout << "checkMemory: You have ";
	std::cout << status.ullAvailPhys / DIV;
	std::cout << " MB of available Physical Memory" << std::endl;
	
	std::cout << "checkMemory: You have ";
	std::cout << status.ullAvailVirtual / DIV;
	std::cout << " MB of available Virtual Memory" << std::endl;
}

//Displays the CPU speed and architecture to the console. 
void displayCPUStats() {
	//esaac this is the function you're working with
}

//Program starts here
int main() {
	isOnlyInstance();
	checkStorage(300000000);
	checkMemory(1000 * DIV, 1000 * DIV);
	displayCPUStats();

	return 0;
}

