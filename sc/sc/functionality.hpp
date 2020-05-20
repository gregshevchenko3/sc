#pragma once
#include "matrix_row.hpp"
#include "maths_operations.h"

#include <map>
#include <utility>
#include <cstdlib>
#include <iostream>

template <typename Tnumeric>
void quit_(const matrix_row<Tnumeric>& arglist, matrix_row<Tnumeric>& result) {
	exit(0);
}
template <typename Tnumeric>
void help_(const matrix_row<Tnumeric>& arglist, matrix_row<Tnumeric>& result) {
	std::cout << "\t\tabs(x) - absolute value of `x` |x|" << std::endl << std::endl;
	std::cout << "\t\t\t\tTRIGONOMETRIC FUNCTIONS" << std::endl;
	std::cout << "\t\tsin(x) - sine of an angle of `x` radiant" << std::endl;
	std::cout << "\t\tcos(x) - cosine of an angle of `x` radiant" << std::endl;
	std::cout << "\t\ttg(x) - tangent of an angle of `x` radiant" << std::endl;
	std::cout << "\t\tctg(x) - cotangent of an angle of `x` radiant" << std::endl;
	std::cout << "\t\tarcsin(x) - value of the arc sine of `x`, expressed in radians." << std::endl;
	std::cout << "\t\tarccos(x) - value of the arc cosine of `x`, expressed in radians." << std::endl;
	std::cout << "\t\tarctg(x) - value of the arc tangent of `x`, expressed in radians." << std::endl;
	std::cout << "\t\tarcctg(x) - value of the arc cotangent of `x`, expressed in radians." << std::endl << std::endl;
	
	std::cout << "\t\t\t\tLOGARITHMS" << std::endl;
	std::cout << "\t\tlog(b, x) - logarithm of `x` to base 'b'" << std::endl;
	std::cout << "\t\tlg(x) - common logaritm of `x`" << std::endl;
	std::cout << "\t\tln(x) - natural logarithm of `x`" << std::endl << std::endl;

	std::cout << "\t\t\t\tSERVICE FUNCTION" << std::endl;
	std::cout << "\t\tquit() - quit programs" << std::endl;
	std::cout << "\t\thelp() - print help" << std::endl << std::endl;
}

template <typename Tnumeric>
void functionality(const char* func_name, const matrix_row<Tnumeric>& parameters, const char* expression, matrix_row<Tnumeric>& result) {
	typedef void(*func)(const matrix_row<Tnumeric>&, matrix_row<Tnumeric>&);
	using function_map = typename std::map<const char*, func>;
	using function_pair = typename std::pair<const char*, func>;

	static function_map fmap;
	static bool once = true;

	if (once) {
		/* Сліжбові функції */
		fmap["quit"] = quit_;
		fmap["help"] = help_;
		/* Модуль числа */
		fmap["abs"] = abs_;
		/* Логарифми */
		fmap["log"] = log_;
		fmap["lg"] = lg_;
		fmap["ln"] = ln_;
		/* Тригонометрія */
		fmap["sin"] = sin_;
		fmap["cos"] = cos_;
		fmap["tg"] = tg_;
		fmap["ctg"] = ctg_;
		fmap["arcsin"] = arcsin_;
		fmap["arccos"] = arccos_;
		fmap["arctg"] = arctg_;
		fmap["arcctg"] = arcctg_;
		once = false;
	}

	auto it = fmap.begin();
	while (it != fmap.end()) {
		if (!strcmp(func_name, it->first)) {
			it->second(parameters, result);
			if (result.empty()) 
				ParserError("Invalid argument, or argument counter", (char*)expression, BOOST_CURRENT_FUNCTION, __FILE__, __LINE__);
			return;
		}
		it++;
	}
	ParserError("Function is not defined", (char*)expression, BOOST_CURRENT_FUNCTION, __FILE__, __LINE__);
};
