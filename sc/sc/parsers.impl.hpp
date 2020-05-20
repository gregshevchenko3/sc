#pragma once

#include <cstring>
#include "maths_operations.h"
#include "ErrorHandling.h"
#include "parsers.hpp"

template<typename Tnumeric>
char * subexpression(char * subexpression, Tnumeric& result)
{
	char* tmp = subexpression;
	subexpression = white_spaces_(subexpression, result);
	if (*subexpression == '(') {
		if (*++subexpression == ')') {
			result = 0;
			return ++subexpression;
		}
		subexpression = addings_(subexpression, result);
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
template<typename Tnumeric>
char * unary_minus_(char * expression, Tnumeric& result)
{
	if (*expression == '-') {
		expression = factorial_(++expression, result);
		result = -result;
	}
	else
		expression = factorial_(expression, result);
	return expression;
}
template<typename Tnumeric>
char * white_spaces_(char * expression, Tnumeric& result)
{
	while (expression && (*expression == ' ' || *expression == '\t'))
		expression++;
	return expression;
}
template<typename Tnumeric>
char* factorial_(char* expression, Tnumeric& result) {
	char* next = expression;
	next = subexpression(expression, result);
	if (next) {
		if (*next == '!') {
			result = factorial_operation(result);
			expression = ++next;
		}
	}
	else
		ParserError("Operand missing", expression, BOOST_CURRENT_FUNCTION, __FILE__, __LINE__);
	return next;
}
template<typename Tnumeric>
char* pow_(char* expression, Tnumeric& result) {
	Tnumeric _lhs;
	char* next = expression;

	next = unary_minus_(expression, result);
	expression = next;

	while (next) {
		if (*next == '^') {
			expression = ++next;
			next = factorial_(expression, _lhs);
			result = pow_operation(result, _lhs);
			expression = next;
		}
		else
			break;
	}
	return expression;
}
template<typename Tnumeric>
char* factors_(char* expression, Tnumeric& result) {
	Tnumeric _lhs;
	char* next = expression;

	next = pow_(expression, result);
	expression = next;

	while (next) {
		switch (*next) {
		case '*':
			expression = ++next;
			next = pow_(expression, _lhs);
			result *= _lhs;
			expression = next;
			break;
		case '/':
			expression = ++next;
			next = pow_(expression, _lhs);
			result /= _lhs;
			expression = next;
			break;
		default:
			next = nullptr;
		}
	}
	return expression;
}
/*
 * adding and substracting
 */
template<typename Tnumeric>
char* addings_(char* expression, Tnumeric& result) {
	Tnumeric _lhs;
	char* next = expression;

	next = factors_(expression, result);
	expression = next;

	while (next) {
		switch (*next) {
		case '+':
			next = factors_(++expression, _lhs);
			result += _lhs;
			expression = next;
			break;
		case '-':
			next = factors_(++expression, _lhs);
			result -= _lhs;
			expression = next;
			break;
		default:
			next = nullptr;
		}
	}
	return expression;
}
