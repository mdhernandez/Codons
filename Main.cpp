//Author: Michael Hernandez
//Date Last Modified: 6/7/2016

#include "Functions.h"

int main() {
	
	std::ifstream inFile;
	inFile.open("input.txt");
	std::ofstream outFile;
	outFile.open("output.txt");
	
	if (inFile.fail()) {
		return 1;
	}

	std::vector<char> firstStrand;

	int vLength = 0;

	firstStrand = copyLineOfChars(inFile, outFile, vLength);

	inFile.close();

	codon(firstStrand, outFile, vLength);

	outFile.close();

	return 0;
}