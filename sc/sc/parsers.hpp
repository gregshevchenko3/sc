#pragma once

#include "functionality.hpp"
#include <boost/bind/bind.hpp>
#include <boost/function.hpp>

template <typename action, typename operand_parser> using parser_extra = std::pair<std::map<const char*, action>, operand_parser>;
template <typename Tnumeric> using action = void(*)(Tnumeric& a, const Tnumeric& b);
template <typename Tnumeric> using operand_parser = boost::function<char* (char* expression, Tnumeric& result)>;

/**
 * ����� �������.
 * ����� ������ ������ �������� �� ������� ��������, � ��������� �� �����, � ����� ���������� ���������.
 * ����� ������ ������� �������� �� ������ ������, ������ �� � ���, �� �� ������ ���������.
 * ��� ���� ����� ������ ������� ���� ������� ��������, ���� ����� �������� �����, �� � ���������.
 */

template <typename Tnumeric> 
char* binary_operator_(const parser_extra<action<Tnumeric>, operand_parser<Tnumeric>> extra, char* expression, Tnumeric& result);


char* function_(char * expression, matrix_row<double>& result);
template <typename Tnumeric> char* subexpression(char* subexpression, Tnumeric& result);
template <typename Tnumeric> char* unary_minus_(char* expression, Tnumeric& result);
template <typename Tnumeric> char* white_spaces_(char* expression, Tnumeric& result);
template <typename Tnumeric> char* number_(char* expression, Tnumeric& result);
template <typename Tnumeric> char* factorial_(char* expression, Tnumeric& result);
/* ����� ����� � ����� ������� */
template <typename Tnumeric> Tnumeric execute(char* expression);

#include "parsers.impl.hpp"
