// ImNotAWrapper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <direct.h>
#include <iostream>


bool isOnlyInstance() {
	//Terry your shit goes here, please use toilet paper
	return true;
}
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
void checkMemory() {

}
void displayCPUStats() {

}

int main() {
	isOnlyInstance();
	checkStorage(300000000);
	checkMemory();
	displayCPUStats();

	return 0;
}

