#include "fileio.hpp"
#include <iostream>
#include <fstream>

void function1() {
	std::ifstream file("fileio-text.txt");

	if (!file.is_open()) {
		std::cout << "Unable to open file\n";
		// return from function;
	}
	char ch;
	do {
		file.get(ch);
		if (ch != ' ') {
			std::cout << ch;
		}
	} while (file.eof() == false && ch != ' ');
	file.close();

	std::cout << std::endl;
}

void function2() {

	std::ifstream file("fileio-data-1.txt");

	if (!file.is_open()) {
		std::cout << "Unable to open file\n";
		// return from function;
	}
	int sum = 0;
	int temp1 = 0;
	int temp = 0;
	int temp2 = 0;
	int digit = 0;
	char ch = '0';
	// file >> ch;
	for (int i = 0; i < 2; ++i) {
		digit = 0;
		temp = 0;
		temp2 = 0;
		do {
			file >> ch;
			if (ch != ';') {
				temp = ch - '0';
				//std::cout << temp;
			}
			if (digit == 0 && ch != ';') {
				temp1 = temp;
				//std::cout << temp << std::endl;
			}
			if (digit == 1 && ch != ';') {
				temp2 = temp1;
				temp2 = temp2 * 10;
				//std::cout << temp2 << std::endl;
			} digit++;
		} while (file.eof() == false && ch != ';');
		//std::cout << digit << std::endl;
		//if (digit == 1) {
			sum += temp + temp2;
		//}
		//sum += temp;
	}
	std::cout << sum << std::endl;
	//std::cout << "sum:" << sum;
	file.close();

}


int main() {

	function1();
	function2();
	system("pause");
}
