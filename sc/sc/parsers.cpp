#include "parsers.hpp"

const parser_extra<action<matrix_row<double>>, operand_parser<matrix_row<double>>> pow_extra = {
	{
		{"^", [](auto& a, const auto& b) {auto c = pow_operation(a, b); a = c; }},
	},
	unary_minus_<matrix_row<double>>
};
const parser_extra<action<matrix_row<double>>, operand_parser<matrix_row<double>>> factors_extra = {
	{
		{"*", [](auto& a, const auto& b) {a *= b; }},
		{"/", [](auto& a, const auto& b) {a /= b; }},
	},
	boost::bind(binary_operator_<matrix_row<double>>, pow_extra, boost::placeholders::_1, boost::placeholders::_2)
};
const parser_extra<action<matrix_row<double>>, operand_parser<matrix_row<double>>> addings_extra = {
	{
		{"+", [](auto& a, const auto& b) {a += b; }},
		{"-", [](auto& a, const auto& b) {a -= b; }},
	},
	boost::bind(binary_operator_<matrix_row<double>>, factors_extra, boost::placeholders::_1, boost::placeholders::_2)
};
const parser_extra<action<matrix_row<double>>, operand_parser<matrix_row<double>>> comma_extra = {
	{
		{",", [](auto& a, const auto& b) {a.push_back(b.back()); }},
	},
	boost::bind(binary_operator_<matrix_row<double>>, addings_extra, boost::placeholders::_1, boost::placeholders::_2)
};

//template<>
//char* comma_<matrix_row<double>>(char * expression, matrix_row<double>& result)
//{
//	char* next = expression;
//	matrix_row<double> _rhs;
//	next = addings_(expression, result);
//	expression = next;
//
//	while (next) {
//		if (*next == ',') {
//			expression = ++next;
//			next = addings_(expression, _rhs);
//			result.push_back(_rhs.back());
//			expression = next;
//		}
//		else
//			break;
//	}
//	return expression;
//}
template<> char* number_<matrix_row<double>>(char* expression, matrix_row<double>& result) {
	char* end = nullptr;
	result.push_back(strtod(expression, &end));
	if (end == expression) 
		return function_(expression, result);
	else
		return end;
}
template <> char* subexpression<matrix_row<double>>(char* subexpression, matrix_row<double>& result) {
	char* tmp = subexpression;
	subexpression = white_spaces_(subexpression, result);
	if (*subexpression == '(') {
		if (*++subexpression == ')') {
			if (result.empty()) result.push_back(0.);
			else
				result.back() = 0.;
			return ++subexpression;
		}
		subexpression = binary_operator_(comma_extra, subexpression, result);
		if (*subexpression == ')')
			++subexpression;
		else
			if (*subexpression == 0)
				ParserError("')' missing", tmp, BOOST_CURRENT_FUNCTION, __FILE__, __LINE__);
	}
	else
		subexpression = number_(subexpression, result);
	return white_spaces_(subexpression, result);
}
char* function_(char * expression, matrix_row<double>& result)
{
	std::string func_name = "";
	// Отримати ім'я функції
	while ((*expression >= 'a' && *expression <= 'z') ||
		(*expression >= 'A' && *expression <= 'Z') ||
		(*expression >= '0' && *expression <= '9') ||
		*expression == '_') func_name.push_back(*expression++);
	if (func_name.empty()) return nullptr;
	matrix_row<double> parameters;
	char* funcN = subexpression(expression, parameters);
	functionality(func_name.c_str(), parameters, expression, result);
	return funcN;
}
template<> matrix_row<double> execute<matrix_row<double>>(char * expression)
{
	matrix_row<double> result;
	char* tmp = binary_operator_(comma_extra, expression, result);
	if (!tmp || *tmp != 0) {
		std::string error = "Unexpected char '";
		error.push_back(*tmp);
		error.push_back('\'');
		ParserError(error.c_str(), tmp, BOOST_CURRENT_FUNCTION, __FILE__, __LINE__);
	}
	else
		return result;
}
