#include <iostream>
#include <cstring>

#include <string>

#include "ErrorHandling.h"
#include "parsers.hpp"
#include "matrix_row.hpp"


int main() {
	double res = 0.0;
	std::cout << "Simple calculator. For exit type `quit()`" << std::endl;
	std::cout << "Simple calculator. For help type `help()`" << std::endl;
	while (1) {
		std::string line;
		std::cout << "> ";
		std::getline(std::cin, line);

		if (!line.empty()) {
			char* expr = (char*)line.c_str();
			try {
				std::cout << execute<matrix_row<double>>(expr).back() << std::endl;
			}
			catch (const std::exception& e) {
				CatchError(e, expr);
			}
		}
		line.~basic_string();
	}
	return 0;
}

