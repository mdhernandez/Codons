//Author: Michael Hernandez
//Date Last Modified: 6/7/2016

#include"Functions.h"

void codon(std::vector<char> code, std::ofstream& of, int length) {
	char codon1[3];
	int counter = 0;
	std::string sequence;
	while (sequence != "Met") {
		codon1[0] = code[0 + counter];
		codon1[1] = code[1 + counter];
		codon1[2] = code[2 + counter];
		sequence = codonConvert(codon1);
		counter += 3;
	}//All codon sequences must start with the Met codon

	if (sequence == "Met") {
		of << "Met" << " ";
	}

	while (sequence != "STOP" && counter < length - 2) {
		codon1[0] = code[0 + counter];
		codon1[1] = code[1 + counter];
		codon1[2] = code[2 + counter];
		sequence = codonConvert(codon1);
		of << sequence << " ";
		counter += 3;
	}//codon sequences stop when a STOP codon is found
}


std::string codonConvert(char codon[3]) {
	std::string conversion = "";
	switch (codon[0]) {
	case 'A':
		switch (codon[1]) {
		case 'A':
			switch (codon[2]) {
			case 'A':
			case 'G':
				conversion = "Lys";
				break;
			case 'T':
			case 'C':
				conversion = "Asn";
				break;
			}
			break;
		case 'G':
			switch (codon[2]) {
			case 'A':
			case 'G':
				conversion = "Arg";
			case 'T':
			case 'C':
				conversion = "Ser";
				break;
			}
			break;
		case 'T':
			switch (codon[2]) {
			case 'G':
				conversion = "Met";
				break;
			case 'A':
			case 'T':
			case 'C':
				conversion = "Ile";
				break;
			}
			break;
		case 'C':
			conversion = "Thr";
			break;
		}
		break;
	case 'G':
		switch (codon[1]) {
		case 'A':
			switch (codon[2]) {
			case 'A':
			case 'G':
				conversion = "Glu";
				break;
			case 'T':
			case 'C':
				conversion = "Asp";
				break;
			}
			break;
		case 'G':
			conversion = "Gly";
			break;
		case 'T':
			conversion = "Val";
			break;
		case 'C':
			conversion = "Ala";
			break;
		}
		break;
	case 'T':
		switch (codon[1]) {
		case 'A':
			switch (codon[2]) {
			case 'A':
			case 'G':
				conversion = "STOP";
				break;
			case 'T':
			case 'C':
				conversion = "Tyr";
				break;
			}
			break;
		case 'G':
			switch (codon[2]) {
			case 'A':
				conversion = "STOP";
				break;
			case 'G':
				conversion = "Trp";
				break;
			case 'T':
			case 'C':
				conversion = "Cys";
				break;
			}
			break;
		case 'T':
			switch (codon[2]) {
			case 'A':
			case 'G':
				conversion = "Leu";
				break;
			case 'T':
			case 'C':
				conversion = "Phe";
				break;
			}
			break;
		case 'C':
			conversion = "Ser";
			break;
		}
		break;
	case 'C':
		switch (codon[1]) {
		case 'A':
			switch (codon[2]) {
			case 'A':
			case 'G':
				conversion = "Gln";
				break;
			case 'T':
			case 'C':
				conversion = "His";
				break;
			}
			break;
		case 'G':
			conversion = "Arg";
			break;
		case 'T':
			conversion = "Leu";
			break;
		case 'C':
			conversion = "Pro";
			break;
		}
		break;
	}
	return conversion;
}

std::vector<char> copyLineOfChars(std::ifstream& inf, std::ofstream& outf, int& count) {
	char temp;
	std::vector<char> tempVec;
	while (inf.good() && inf >> temp) {
		outf << temp << " ";
		tempVec.push_back(temp);
		count++;
	}
	outf << std::endl;
	return tempVec;
}