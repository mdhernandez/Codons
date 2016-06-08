//Author: Michael Hernandez
//Date Last Modified: 6/7/2016

#include<vector>
#include<iostream>
#include<fstream>
#include<string>

void codon(std::vector<char>, std::ofstream&, int);//determines the start and stop codons in the sequence and outputs the codons to the output file
std::string codonConvert(char[3]);//converts a char array of three chars to the corresponding shortened version of the name of the codon it forms
std::vector<char> copyLineOfChars(std::ifstream&, std::ofstream&, int&);
//takes any number of characters from an input file, stores copies of them in a vector and outputs the characters to the output file