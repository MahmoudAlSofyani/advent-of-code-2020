#include <iostream>
#include <fstream>
#include <string>
int main() {

	std::fstream inputFile;
	inputFile.open("input.txt", std::ios::in);

	if (!inputFile) {
		std::cout << "Error opening the file." << std::endl;
		return -1;
	}
	else {
		std::cout << "Beginning program..." << std::endl;
	}

	std::string input;
	int numArray[200];
	int count = 0;

	// Read the file until end of file is true
	// While every line is read, convert it to an int and store it in the array

	while (!inputFile.eof()) {
		inputFile >> input;
		numArray[count] = std::stoi(input);
		count++;
	}

	// For each element in the array, check it against all the other elements if it adds to 2020
	for (int i = 0; i < count; i++) {
		for (int j = count; j > 0; j--) {
			if (numArray[i] + numArray[j] == 2020) {
				std::cout << numArray[i] * numArray[j] << std::endl;
				return 0;
			}
		}
	}

	inputFile.close();
	return 0;
}