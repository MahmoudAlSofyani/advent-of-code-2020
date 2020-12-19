#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

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
	std::string lowerLimit;
	std::string upperLimit;
	char policyLetter;
	std::string password;
	int validPassword = 0;

	//Part one
	// While there are lines to be read
	// Parse it for relevant information by using substr
	// then for each letter in the password, compare it with the policy letter and count them
	// Then verify if the password meets the policy
	while (std::getline(inputFile, input)) {
		int policyCounter = 0;
		lowerLimit = input.substr(0, input.find('-'));
		upperLimit = input.substr(input.find('-') + 1, input.find(' ') - 1);
		policyLetter = input.at(input.find(" ") + 1);
		password = input.substr(input.find(':') + 2);

		for (int i = 0; i < password.length(); i++) {
			if (password[i] == policyLetter) {
				policyCounter++;
			}
		}

		if (policyCounter >= std::stoi(lowerLimit) && policyCounter <= std::stoi(upperLimit)) {
			validPassword++;
		}
	}

	std::cout << "Part one answer: " << validPassword << std::endl;

	inputFile.close();
	inputFile.open("input.txt", std::ios::in);

	validPassword = 0;
	std::string firstPosition;
	std::string secondPosition;
	bool firstValid = false;
	bool secondValid = false;

	//Part two
	// Parse the string same as above
	// Check positions with policy letter and if they match set their respective position booleans to true
	//Then check if at most one position is valid, if it is incremement validPassword
	while (std::getline(inputFile, input)) {

		firstPosition = input.substr(0, input.find('-'));
		secondPosition = input.substr(input.find('-') + 1, input.find(' ') - 1);
		policyLetter = input.at(input.find(" ") + 1);
		password = input.substr(input.find(":") + 2);

		(password[std::stoi(firstPosition) - 1] == policyLetter)  ? firstValid = true : firstValid = false;
		(password[std::stoi(secondPosition) - 1] == policyLetter) ? secondValid = true : secondValid = false;
		if (firstValid != secondValid) validPassword++;
	}

	std::cout << "Part two answer: " << validPassword << std::endl;
	inputFile.close();
	return 0;
}