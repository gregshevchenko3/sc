#pragma once

template<typename Tnumeric>
char * binary_operator_(const parser_extra<action<Tnumeric>, operand_parser<Tnumeric>> extra, char * expression, Tnumeric & result)
{
	char* next = expression;
	next = extra.second(expression, result);
	expression = next;
	while (next) {
		Tnumeric _rhs;
		auto it = extra.first.begin(), it_end = extra.first.end();
		while (it != it_end) {
			auto len = strlen(it->first);
			if (!strncmp(expression, it->first, len)) {
				expression += len;
				next = extra.second(expression, _rhs);
				it->second(result, _rhs);
				expression = next;
				break;
			}
			it++;
		}
		if (it == it_end) break;
	}
	return expression;
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