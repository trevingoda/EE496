#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

void test(int file) {
	int Ox, Oy, x, y;
	std::string fname = "scan_";
	std::ifstream myfile;

	for (int i = 1; i < file; i++) {
		std::string String = static_cast<std::ostringstream*>(&(std::ostringstream() << i))->str();
		fname.append(String);

		myfile.open(fname);

		myfile >> Ox >> Oy; //takes the first line of the file and sets it as the origin.
		std::cout << "Ox: " << Ox << "Oy: " << Oy << std::endl;
		while (myfile >> x >> y) {
			std::cout << "x: " << x << "y: "<< y << std::endl;
		}
		myfile.close();
	}
}