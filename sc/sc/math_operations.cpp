#include "maths_operations.h"

template <> double pow_operation<double>(double base, double exp) {
	double result = 0.0;
	if (base < 0) {
		double whole, fraction;
		fraction = std::modf(exp, &whole);

		if (fraction == 0) {
			if (whole == 0) return 1.0; // 0-й степінь дійсного числа завжди == 1.
			else result = std::pow(base, exp); // 
		}
		else
			if (std::modf(1 / (2 * fraction), &fraction) > 0) {
				result = -std::pow(-base, exp);
			}
			else
				MathError("Unable to calculate the square root of a negative number", BOOST_CURRENT_FUNCTION, __FILE__, __LINE__);
	}
	else
		result = std::pow(base, exp);
	return result;
}

template <> double factorial_operation<double>(double n) {
	double integral_n = 1.0;
	if (modf(n, &integral_n) > 0 || n < 0) MathError("Unable to calculate factorial of a fraction or negative number", BOOST_CURRENT_FUNCTION, __FILE__, __LINE__);
	if (integral_n == 0.0)
		return 1.0;
	else
		integral_n *= factorial_operation(integral_n - 1);
	return integral_n;
}

#include "matrix_row.hpp"

template<> matrix_row<double> pow_operation<matrix_row<double>>(matrix_row<double> base, matrix_row<double> exp) {
	matrix_row<double> res;
	res.push_back(pow_operation<double>(base.back(), exp.back()));
	return res;
}

template <> matrix_row<double> factorial_operation<matrix_row<double>>(matrix_row<double> n)
{
	matrix_row<double> res;
	res.push_back(factorial_operation<double>(n.back()));
	return res;
}

/** Модуль числа*/
template <> void abs_<double>(const matrix_row<double>& arglist, matrix_row<double>& result) {
	if (1 != arglist.size()) {
		result.erase(result.begin(), result.end());
		return;
	}
	result.back() = abs(arglist.back());
}
/* Логарифми */
template <> void log_<double>(const matrix_row<double>& arglist, matrix_row<double>& result) {
	if (2 != arglist.size() || arglist[1] < 0) {
		result.erase(result.begin(), result.end());
		return;
	}
	double base = arglist[0], x = arglist[1];
	result.back() = log(x) / log(base);
}
template <> void lg_<double>(const matrix_row<double>& arglist, matrix_row<double>& result) {
	if (1 != arglist.size() || arglist[0] < 0) {
		result.erase(result.begin(), result.end());
		return;
	}
	result.back() = log10(arglist[0]);
}
template <> void ln_<double>(const matrix_row<double>& arglist, matrix_row<double>& result) {
	if (1 != arglist.size() || arglist[0] < 0) {
		result.erase(result.begin(), result.end());
		return;
	}
	result.back() = log(arglist[0]);
}

/** Тригонометрія */
template <> void sin_<double>(const matrix_row<double>& arglist, matrix_row<double>& result) {
	if (1 != arglist.size()) {
		result.erase(result.begin(), result.end());
		return;
	}
	result.back() = sin(arglist.back());
}
template <> void cos_<double>(const matrix_row<double>& arglist, matrix_row<double>& result) {
	if (1 != arglist.size()) {
		result.erase(result.begin(), result.end());
		return;
	}
	result.back() = cos(arglist.back());
}

template <> void tg_<double>(const matrix_row<double>& arglist, matrix_row<double>& result) {
	if (1 != arglist.size()) {
		result.erase(result.begin(), result.end());
		return;
	}
	result.back() = tan(arglist.back());
}
template <> void ctg_<double>(const matrix_row<double>& arglist, matrix_row<double>& result) {
	if (1 != arglist.size()) {
		result.erase(result.begin(), result.end());
		return;
	}
	result.back() = 1/tan(arglist.back());
}
template <> void arcsin_<double>(const matrix_row<double>& arglist, matrix_row<double>& result) {
	if (1 != arglist.size()) {
		result.erase(result.begin(), result.end());
		return;
	}
	result.back() = asin(arglist.back());
}
template <> void arccos_<double>(const matrix_row<double>& arglist, matrix_row<double>& result) {
	if (1 != arglist.size()) {
		result.erase(result.begin(), result.end());
		return;
	}
	result.back() = acos(arglist.back());
}

template <> void arctg_<double>(const matrix_row<double>& arglist, matrix_row<double>& result) {
	if (1 != arglist.size()) {
		result.erase(result.begin(), result.end());
		return;
	}
	result.back() = atan(arglist.back());
}
template <> void arcctg_<double>(const matrix_row<double>& arglist, matrix_row<double>& result) {
	if (1 != arglist.size()) {
		result.erase(result.begin(), result.end());
		return;
	}
	result.back() = atan(1/arglist.back());
}